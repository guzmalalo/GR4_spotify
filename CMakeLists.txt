cmake_minimum_required(VERSION 3.26)
project(GR4_spotify C)

set(CMAKE_C_STANDARD 11)

add_executable(Spotify main.c
        chanson.c
        chanson.h)
