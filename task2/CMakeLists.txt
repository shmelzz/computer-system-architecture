cmake_minimum_required(VERSION 3.16)
project(dzsecond)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)


add_executable(dzsecond main.cpp container.cpp container.h shape.cpp shape.h circle.cpp circle.h triangle.cpp triangle.h rectangle.cpp rectangle.h rnd.h)
