cmake_minimum_required(VERSION 3.16)
project(BiteBytes)

set(PACKAGE_VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

include(CMakePackageConfigHelpers)
include(CMakeSources.cmake)

add_library(BiteBytes SHARED ${SRC})

set_target_properties(BiteBytes PROPERTIES LINKER_LANGUAGE CXX)