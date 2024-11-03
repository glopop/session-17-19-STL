cmake_minimum_required(VERSION 3.10)
project(ZipfsLaw)


include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(zipfs_containers main_zipfs_containers.cpp)

add_executable(zipfs_algorithms main_zipfs_algorithms.cpp)
