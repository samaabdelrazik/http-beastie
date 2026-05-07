cmake_minimum_required(VERSION 3.21)
project(Assignmnet3)

find_package(Boost REQUIRED)
add_executable(app src/main.cpp src/utils.cpp include/utils.hpp)

target_include_directories(app PRIVATE include)
target_include_directories(app PRIVATE ${Boost_INCLUDE_DIRS})
