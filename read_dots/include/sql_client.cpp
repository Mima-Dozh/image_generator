#include "sql_client.h"

SQLClient::SQLClient(std::filesystem::path file_path) {
    int exit = 0;
    exit = sqlite3_open(file_path.string().c_str(), &DB_);
    char* messaggeError;
    exit = sqlite3_exec(DB_, create_tabel_sql_.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        std::cerr << messaggeError << std::endl;
        sqlite3_free(messaggeError);
    }
}

SQLClient::~SQLClient() {
    sqlite3_close(DB_);
}

void SQLClient::insert_point_info(PointInfo point_info) {
    std::string sql = "INSERT INTO point_info(file_name, point_group, x, y)\n"
                      "values ( '" +
                      point_info.file_name_.string() + "', '" +
                      point_info.group_ + "', " +
                      std::to_string(point_info.x_) + ", " +
                      std::to_string(point_info.y_) +
                      ");";

    char* messaggeError;
    int exit = 0;
    exit = sqlite3_exec(DB_, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error insert point" << std::endl;
        std::cerr << messaggeError << std::endl;
        sqlite3_free(messaggeError);
    }
}
