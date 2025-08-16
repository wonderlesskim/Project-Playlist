cmake_minimum_required(VERSION 3.10)
project(PlaylistProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(PlaylistProject src/main.cpp src/Playlist.cpp)

