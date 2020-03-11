cmake_minimum_required(VERSION 3.15)
project(UserBaseLinux)

set(CMAKE_CXX_STANDARD 11)

add_executable(UserBaseLinux main.cpp UserProcess.h UserProcess.cpp)