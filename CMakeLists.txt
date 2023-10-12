cmake_minimum_required(VERSION 3.26)
project(code)

set(CMAKE_CXX_STANDARD 17)

add_executable(code main.cpp
        player/source/Player.cpp
        player/headers/Player.h
        player/headers/SIdes.h
        player/source/PlayerController.cpp
        player/headers/PlayerController.h
        field/source/Field.cpp
        field/headers/Field.h
        field/source/Cell.cpp
        field/headers/Cell.h
        field/headers/Point.h
        field/headers/CellType.h)
