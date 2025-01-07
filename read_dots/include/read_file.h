#pragma once

#include <vector>
#include <fstream>
#include <regex>

#include <rapidjson/istreamwrapper.h>
#include <rapidjson/document.h>

#include "PointInfo.h"


std::vector<PointInfo> read_bin_file(const std::filesystem::path& file_path);

std::vector<PointInfo> read_txt_file(const std::filesystem::path& file_path);

std::vector<PointInfo> read_json_file(std::filesystem::path file_path);