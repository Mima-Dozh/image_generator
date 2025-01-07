#!/bin/bash

cmake -B ./build -S ./read_dots/
cmake --build ./build/

./build/read_dots $@
python3 ./make_image/__main__.py
