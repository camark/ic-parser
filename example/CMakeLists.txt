cmake_minimum_required(VERSION 2.8)

link_directories(../lib)
link_libraries(icparser)

add_executable(demo demo.c)