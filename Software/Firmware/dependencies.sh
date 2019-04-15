#!/bin/bash
cd lib/
if [ -d "wiringPi" ]; then
  rm -rf wiringPi
fi
git clone git://git.drogon.net/wiringPi
cd wiringPi
./build
cd ../
rm -rf wiringPi
if [ -d "pca9685" ]; then
  rm -rf pca9685
fi
git clone https://github.com/Reinbert/pca9685.git
cd pca9685/src
sudo make install
cd ../



