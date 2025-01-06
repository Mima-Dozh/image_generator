#include "PointInfo.h"

PointInfo::PointInfo(std::filesystem::path file_name, std::string group, uint32_t x, uint32_t y) {
    file_name_ = file_name;
    group_ = group;
    x_ = x;
    y_ = y;
}

PointInfo::PointInfo(std::filesystem::path file_name, BinPointInfo bin_point) {
    file_name_ = file_name;
    group_ = std::to_string(bin_point.group);
    x_ = bin_point.x;
    y_ = bin_point.y;
}