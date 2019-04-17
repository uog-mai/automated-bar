cmake_minimum_required(VERSION 3.5.1)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")
set(PYBIND11_CPP_STANDARD -std=c++11)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# For creating python modules in c++
execute_process(COMMAND bash -c "echo `python3-config --extension-suffix`" OUTPUT_VARIABLE extension)
execute_process(COMMAND bash -c "echo `python3 -m pybind11 --includes`" OUTPUT_VARIABLE paths)

# Logging
message( ${paths} )

# Format Includes for use with CMake
string(REGEX REPLACE "\n$" "" extension "${extension}")
string(REPLACE ".so" "" extension ${extension})
string(REPLACE "-I" "" paths ${paths})
string(REPLACE " " ";" ARG_LIST ${paths})

# Logging
message( ${ARG_LIST} )
message(extension${extension})

# Declare Project
project(automated-bar)

include_directories(
	"${CMAKE_SOURCE_DIR}/include/"
	"${CMAKE_SOURCE_DIR}/lib/"
	${ARG_LIST} 		     
)

add_library(DrinksConfig SHARED src/DrinksConfig.cpp)

add_library(extension${extension} SHARED src/PyDrinkServer.cpp src/DrinksConfig.cpp src/DrinkServer.cpp src/ServoHandler.cpp src/ProximitySensor.cpp src/PiSetup.cpp lib/HX711/HX711.cpp)

#add_library(DrinkServer SHARED src/DrinkServer.cpp)
#add_library(ServoHandler SHARED src/ServoHandler.cpp)
#add_library(HX711 SHARED lib/HX711/HX711.cpp)

target_link_libraries(extension${extension}
	DrinksConfig
	#DrinkServer
	#ServoHandler
	#HX711
	-lwiringPi
	-lwiringPiPca9685
)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
  # Don't Install Google Test if its already installed.
  IF(NOT GTEST_INSTALLED MATCHES TRUE)
  
    find_package(Threads REQUIRED)
    
    # Enable ExternalProject CMake module
    include(ExternalProject)
    
    # Download and install GoogleTest
    ExternalProject_Add(
      gtest
      URL https://github.com/google/googletest/archive/release-1.8.1.zip
      PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
      # Disable install step
      INSTALL_COMMAND ""
    )
    
    # Get GTest source and binary directories from CMake project
    ExternalProject_Get_Property(gtest source_dir binary_dir)

    # Create a libgtest target to be used as a dependency by test programs
    add_library(libgtest IMPORTED STATIC GLOBAL)
    add_dependencies(libgtest gtest)
    
    # Set libgtest properties
    set_target_properties(libgtest PROPERTIES
      "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
      "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )
    
    # Create a libgmock target to be used as a dependency by test programs
    add_library(libgmock IMPORTED STATIC GLOBAL)
    add_dependencies(libgmock gtest)
    
    # Set libgmock properties
    set_target_properties(libgmock PROPERTIES
      "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
      "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )
  ENDIF(NOT GTEST_INSTALLED MATCHES TRUE)
  enable_testing()
  add_subdirectory(test)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)
