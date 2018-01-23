# Project configuration
cmake_minimum_required(VERSION 2.7)
project(OpenSSLTest)

# Use C++11
set(CMAKE_CXX_STANDARD 11)

# Project source files
set(SOURCE_FILES main.cpp)
add_executable(OpenSSLTest ${SOURCE_FILES})

# OpenSSL (find, include, link) 
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARIES})