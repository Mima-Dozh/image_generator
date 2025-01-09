#!/bin/bash

bash ./build_my_project.sh

if [ ! -d ./data_base ]; then
  mkdir data_base
fi
echo "" > ./data_base/image.db

./build/read_dots $@

if [ ! -d ./image ]; then
  mkdir image
fi

pip install -r requirements.txt
python3 ./make_image/__main__.py
