cmake_minimum_required(VERSION 3.15)
project(cd_mking C)

set(CMAKE_C_STANDARD 99)

add_executable(cd_mking main.c cd_making.h best_fit.c best_fit.h firs_fit.c firs_fit.h)