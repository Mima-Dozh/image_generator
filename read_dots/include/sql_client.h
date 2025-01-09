#pragma once

#include <iostream>
#include <string>

#include <sqlite3.h>

#include "PointInfo.h"

struct SQLClient {
public:
    SQLClient(std::filesystem::path file_path);
    ~SQLClient();

    void insert_point_info(PointInfo point_info);

private:
    sqlite3* DB_;

    const std::string create_tabel_sql_ = "CREATE TABLE IF NOT EXISTS point_info("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "file_name TEXT not NULL,"
                      "point_group TEXT not NULL,"
                      "x int,"
                      "y int);";
};