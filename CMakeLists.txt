cmake_minimum_required(VERSION 3.10)

# Set the project name
project(FixAllSystems VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable and source files
add_executable(FixAllSystems 
    src/main.cpp
)

# Include directories for header files
include_directories(include)
