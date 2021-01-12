cmake_minimum_required(VERSION 3.5)
PROJECT(hello)
set(CMAKE_TOOLCHAIN_FILE ./toolchain.cmake)
ADD_SUBDIRECTORY(src bin)
