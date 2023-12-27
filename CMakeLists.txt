cmake_minimum_required(VERSION 3.16)
project(Algorithms
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "A collection of algorithms and data structures."
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(sorting)
add_subdirectory(dynamic_programming)

cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)