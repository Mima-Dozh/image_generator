#!/bin/bash

create_build_folder="cmake -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT"/scripts/buildsystems/vcpkg.cmake -B ./build -S ./read_dots/"

eval $create_build_folder
cmake --build ./build/

pip install -r requirements.txt
