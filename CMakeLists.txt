cmake_minimum_required(VERSION 3.14)
project(UTPod)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UTPod
        UtPodDriver.cpp
        Song.h
        Song.cpp
        UtPod.cpp
        UtPod.h)
