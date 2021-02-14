cmake_minimum_required(VERSION 3.17)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snake main.cpp
        include/input.h
        include/snake.h
        include/renderer.h
        include/field.h
        include/common.h

        src/input.cpp
        src/snake.cpp
        src/renderer.cpp
        src/field.cpp
        src/common.cpp
        )