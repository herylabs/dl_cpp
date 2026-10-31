cmake_minimum_required(VERSION 3.16)
project(dl_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)   

include_directories(include)

add_executable(dl_cpp
    src/main.cpp
    src/helper.cpp
)