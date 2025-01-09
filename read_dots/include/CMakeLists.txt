cmake_minimum_required(VERSION 3.9.2)
project(parser)


add_library(parser STATIC read_file.cpp)
add_library(PointInfo STATIC PointInfo.cpp)
add_library(sql_client STATIC sql_client.cpp)

find_package(RapidJSON CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(parser
                      PRIVATE rapidjson
                      PRIVATE PointInfo)
target_link_libraries(sql_client
                      PRIVATE unofficial::sqlite3::sqlite3
                      PRIVATE PointInfo)
