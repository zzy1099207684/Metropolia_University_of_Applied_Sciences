cmake_minimum_required(VERSION 3.29)
project(ex20 C)

set(CMAKE_C_STANDARD 11)

add_executable(ex20 main.c
        debug.c
        debug.h)
