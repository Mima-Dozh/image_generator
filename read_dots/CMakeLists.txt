cmake_minimum_required(VERSION 3.9.2)
project(read_dots)

set(SOURCE_EXE main.cpp)

include_directories(include)

add_executable(read_dots main.cpp)

add_subdirectory(include)

find_package(fmt CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(read_dots
                      PRIVATE parser
                      PRIVATE unofficial::sqlite3::sqlite3
                      PRIVATE fmt::fmt)
