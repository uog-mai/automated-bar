#!/bin/bash
if ! [ -x "$(command -v python3.5)" ]; then
  sudo apt-get install python3.5
fi

if ! [ -x "$(command -v python3-dev)" ]; then
  sudo apt-get install python3-dev
fi

if ! [ -x "$(command -v pip3)" ]; then
  sudo apt-get install python3-pip
fi

if ! [ -x "$(command -v build-essential)" ]; then
  sudo apt-get install build-essential
fi

if ! [ -x "$(command -v clang-3.8)" ]; then
  sudo apt-get install clang-3.8
fi

if ! [ -x "$(command -v cmake)" ]; then
  sudo apt-get install cmake
fi

python3 -c 'import pybind11'

if ! [ $? ]; then
  pip3 install pybind11
fi

python3 -c 'import Flask'

if ! [ $? ]; then
  pip3 install Flask
fi


export CXX="/usr/bin/clang++-3.8"
cd Firmware/
bash dependencies.sh
mkdir build
cd ./build
cmake -DCMAKE_BUILD_TYPE=Debug ../
make all -j
ctest --output-on-failure
make clean
cmake -DCMAKE_BUILD_TYPE=Release ../
make all -j

ext=$(python3-config --extension-suffix)
mv libextension$ext ../../Server/	
 
