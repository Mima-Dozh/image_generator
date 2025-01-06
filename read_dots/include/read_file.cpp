#include "read_file.h"

using namespace rapidjson;


std::vector<PointInfo> read_bin_file(const std::filesystem::path& file_path) {
    std::vector<PointInfo> res;
    BinPointInfo bin_point;
    std::ifstream in(file_path, std::ios::binary|std::ios::in);
    while (in.peek() != EOF){
        in.read((char*)&bin_point, sizeof bin_point);
        res.push_back(PointInfo(file_path, bin_point));
    }
    in.close();

    return res;
}

std::vector<PointInfo> read_txt_file(const std::filesystem::path& file_path) {
    std::vector<PointInfo> res;
    std::ifstream in(file_path, std::ios::binary|std::ios::in);
    std::string line;
    while (in.peek() != EOF){
        getline(in, line);
    }
    in.close();

    return res;
}

std::vector<PointInfo> read_json_file(std::filesystem::path file_path) {
    std::vector<PointInfo> res;
    std::ifstream in(file_path, std::ios::binary|std::ios::in);
    IStreamWrapper isw(in);

    Document d;
    d.ParseStream(isw);

    in.close();

    const Value& points = d["points"];

    for (auto& point : points.GetArray()) {
        res.push_back(PointInfo(file_path, point["group"].GetString(), point["x"].GetInt(), point["y"].GetInt()));
    }

    return res;
}
