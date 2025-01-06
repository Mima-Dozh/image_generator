cmake_minimum_required(VERSION 3.9.2)
project(parser)


add_library(parser STATIC read_file.cpp)
add_library(PointInfo STATIC PointInfo.cpp)

find_package(RapidJSON CONFIG REQUIRED)
target_link_libraries(parser PRIVATE rapidjson)
target_link_libraries(parser PRIVATE PointInfo)
