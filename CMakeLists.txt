cmake_minimum_required(VERSION 3.24)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6
        struktury_danych/dynamic_array.cpp
        struktury_danych/OneWayList+Tail.cpp
        struktury_danych/OneWayList.cpp
        struktury_danych/TwoWayList.cpp
        generator.cpp
        testownik.cpp)
