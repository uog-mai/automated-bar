CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

Project(HX711)

set(CMAKE_CXX_FLAGS "-Wall" )
set(CMAKE_CXX_STANDARD 11)
add_executable(readScale readScale.cpp HX711.cpp)

target_link_libraries(readScale -lwiringPi)

