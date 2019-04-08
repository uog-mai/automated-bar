cmake_minimum_required(VERSION 3.5.1)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall" "-shared")
set(PYBIND11_CPP_STANDARD -std=c++11)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

execute_process(COMMAND bash -c "echo `python3-config --extension-suffix" OUTPUT_VARIABLE extension)
execute_process(COMMAND bash -c "echo `python3 -m pybind11 --includes`" OUTPUT_VARIABLE paths)


string(REGEX REPLACE "\n$" "" extension "${extension}")
 
project(automated-bar)

#find_library(wiringPi_LIB wiringPi)
#find_library(wiringPi9685_LIB wiringPiPca9685)

include_directories(
		     /usr/include/python3.5m
		     /usr/local/include/python3.5 
		     /home/$ENV{USER}/.local/include/python3.5m
		     ${CMAKE_CURRENT_SOURCE_DIR}/src/pca9685/src
)
message(extension${extension})
add_library(extension${extension} SHARED MultiServoControl.cpp)

target_link_libraries(extension${extension} -lwiringPi) # ${wiringPi_LIB})
target_link_libraries(extension${extension}  -lwiringPiPca9685)  #${wiringPi9685_LIB})
