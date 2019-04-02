cmake_minimum_required(VERSION 3.13)
project(Life C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(Life
        src/Grid.c
        src/Grid.h
        src/Main.c
        src/Reader.c
        src/Reader.h
        src/Rules.c
        test/ReaderTest.c
        src/Formatted_writer.c
        src/Formatted_writer.h
        src/AsciiArt_writer.c
        src/AsciiArt_writer.h
        src/Generator.c
        src/Generator.h)
