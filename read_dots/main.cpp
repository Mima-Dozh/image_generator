#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

#include "PointInfo.h"
#include "read_file.h"

int main(int argc, char* argv[]){
    std::vector<std::filesystem::path> params(argv + 1, argv+argc);
    std::cout << "argc: " << argc << '\n';
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
            std::cout<< a.file_name_ << std::endl;
            std::cout << a.group_ << std::endl;
            std::cout << a.x_ << ' ' << a.y_ << std::endl;
        }
    }
    return 0;
}
