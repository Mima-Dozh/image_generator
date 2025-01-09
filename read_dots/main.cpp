#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

#include "PointInfo.h"
#include "read_file.h"
#include "sql_client.h"


int main(int argc, char* argv[]){
    std::vector<std::filesystem::path> params(argv + 1, argv+argc);

    SQLClient sql_client("./data_base/image.db");

    for(auto file_path : params) {
        if (!std::filesystem::exists(file_path)) {
            std::cerr << "Don't exists path \"" << file_path << '"' << std::endl;
            return 1;
        }

        std::thread t ([&]() {
            std::vector<PointInfo> points_info;
            auto extension = file_path.extension();

            if (extension == ".bin") {
                points_info = read_bin_file(file_path);
            } else if (extension == ".json") {
                points_info = read_json_file(file_path);
            } else if (extension == ".txt") {
                points_info = read_txt_file(file_path);
            } else {
                std::cerr << "Unknown extension \"" << extension << '"' << std::endl;
                return 1;
            }

            for (auto point_info : points_info) {
                sql_client.insert_point_info(point_info);
            }
        });

        t.join();
    }

    return 0;
}
