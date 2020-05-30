cmake_minimum_required(VERSION 3.16)
project(BiteBytes)

set(PACKAGE_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 14)

include(CMakeSources.cmake)

option(BUILD_IEC_STANDARD "Build to use the IEC standard for conversion" ON)

if (BUILD_IEC_STANDARD MATCHES OFF)
    # enable
    add_compile_options(-DSI_STANDARD)
    message(STATUS "BiteBytes: Building using SI Standard")
endif ()

add_library(BiteBytes SHARED ${SRC})

set_target_properties(BiteBytes PROPERTIES LINKER_LANGUAGE CXX)