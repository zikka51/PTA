cmake_minimum_required(VERSION 3.5)

project(FoamLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FoamLib main.cpp
    fluidDatabase.h
    fluidDatabase.cpp
    menu.h
    menu.cpp
    turbulanceCalculator.h
    turbulanceCalculator.cpp
    yppCalculator.h
    yppCalculator.cpp
    )

