cmake_minimum_required(VERSION 2.8)
project(icparser)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_VERBOSE_MAKEFILE on)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

aux_source_directory(./src SRC_FILES)
add_library(icparser SHARED ${SRC_FILES})
add_library(icparser-static STATIC ${SRC_FILES})
set_target_properties(icparser-static PROPERTIES OUTPUT_NAME "icparser")

#set_target_properties(icparser PROPERTIES VERSION 1.0 SOVERSION 1)