#!/bin/bash

bash ./build_my_project.sh

mkdir data_base
echo "" > ./data_base/image.db

./build/read_dots $@
mkdir image
python3 ./make_image/__main__.py
