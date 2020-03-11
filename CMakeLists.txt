cmake_minimum_required(VERSION 3.15)
project(UserBaseLinux)

set(CMAKE_CXX_STANDARD 11)
set(INC_DIR /usr/local/opt/openssl/include)
set(LINK_DIR /usr/local/opt/openssl/lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(ssl crypto)

add_executable(UserBaseLinux main.cpp UserProcess.h UserProcess.cpp)