cmake_minimum_required(VERSION 3.13)
project(Labo1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

add_executable(Labo1 main.cpp Date.cpp Date.h)