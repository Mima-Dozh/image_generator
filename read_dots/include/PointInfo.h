#pragma once

#include <cinttypes>
#include <filesystem>

struct BinPointInfo{
    uint32_t group:8;
    uint32_t x:12;
    uint32_t y:12;
};

struct PointInfo{
public:
    PointInfo(std::filesystem::path file_path, std::string group, uint32_t x, uint32_t y);

    PointInfo(std::filesystem::path file_path, BinPointInfo bin_point);

    std::filesystem::path file_name_;
    std::string group_;
    uint32_t x_;
    uint32_t y_;
};