#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

#include <sqlite3.h>

#include "PointInfo.h"
#include "read_file.h"


void insert_to_db(sqlite3* DB, PointInfo point_info) {
    std::string sql = "INSERT INTO point_info(file_name, point_group, x, y)\n"
                      "values ( '" +
                      point_info.file_name_.string() + "', '" +
                      point_info.group_ + "', " +
                      std::to_string(point_info.x_) + ", " +
                      std::to_string(point_info.y_) +
                      ");";

    char* messaggeError;
    int exit = 0;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error " << sql << std::endl;
        sqlite3_free(messaggeError);
    }
    else {
        std::cout << "Sucses " << sql << std::endl;
    }
}

int main(int argc, char* argv[]){
    std::vector<std::filesystem::path> params(argv + 1, argv+argc);
    std::cout << "argc: " << argc << '\n';

    sqlite3* DB;
    std::string sql = "CREATE TABLE IF NOT EXISTS point_info("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "file_name TEXT not NULL,"
                      "point_group TEXT not NULL,"
                      "x int,"
                      "y int);";

    int exit = 0;
    exit = sqlite3_open("./data_base/image.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        std::cerr << sql << std::endl;
        sqlite3_free(messaggeError);
    }
    else {
        std::cout << "Table created Successfully" << std::endl;
    }


    for(auto file_path : params) {
        std::cout << file_path << std::endl;
        if (!std::filesystem::exists(file_path)) {
            std::cerr << "Don't exists path \"" << file_path << '"' << std::endl;
            continue;
        }

        std::vector<PointInfo> res;
        auto extension = file_path.extension();

        if (extension == ".bin") {
            res = read_bin_file(file_path);
        } else if (extension == ".json") {
            res = read_json_file(file_path);
        } else if (extension == ".txt") {
            res = read_txt_file(file_path);
        } else {
            std::cerr << "Unknown extension \"" << extension << '"' << std::endl;
        }

        for (auto a : res) {
            insert_to_db(DB, a);
        }
    }

    sqlite3_close(DB);
    return 0;
}
