cmake_minimum_required(VERSION 3.28)
project(LabWork1_2_)

set(CMAKE_CXX_STANDARD 17)

add_executable(LabWork1_2_ main.cpp
        Manager.cpp
        Manager.h
        Symbol.cpp
        Symbol.h
        Console.cpp
        Console.h
        Line.cpp
        Line.h
        Coordinats.cpp
        Coordinats.h
        LineSettings.cpp
        LineSettings.h
)
