cmake_minimum_required(VERSION 3.16)
project(PACman C)

set(CMAKE_C_STANDARD 99)

add_executable(PACman main.c Juego.c Juego.h cmake-build-debug/extras.c)