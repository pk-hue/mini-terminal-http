cmake_minimum_required(VERSION 3.21)
project(pjt_curl_v2)

set(CMAKE_CXX_STANDARD 20)

# Adiciona o vcpkg ao projeto
find_package(CURL REQUIRED)

add_executable(pjt_curl_v2 main.cpp)

target_link_libraries(pjt_curl_v2 PRIVATE CURL::libcurl)
