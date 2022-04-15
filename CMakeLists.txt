cmake_minimum_required(VERSION 3.22.1)

project(
    ray-tracing
    VERSION 1
    DESCRIPTION "Ray Tracing From The Ground Up"
    LANGUAGES CXX
)

add_subdirectory(src)
add_subdirectory(apps)