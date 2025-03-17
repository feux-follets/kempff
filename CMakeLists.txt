cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COMPILE_WARNING_AS_ERROR OFF)
set(CMAKE_COLOR_DIAGNOSTICS ON)
# set(CMAKE_CXX_CLANG_TIDY clang-tidy)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)

include(${CMAKE_SOURCE_DIR}/cmake/StdModule.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/FetchContent.cmake)


set(WARNINGS
		-Wall
		-Wextra
		-Wpedantic
		-Wconversion
		-Wnon-virtual-dtor
		-Wshadow
)
add_compile_options(${WARNINGS})


project(kempff CXX)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)