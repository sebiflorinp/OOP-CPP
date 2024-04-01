cmake_minimum_required(VERSION 3.27)
project(cpplab)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpplab main.cpp
        domain/Car.cpp
        domain/Car.h
        domain/CarValidators.cpp
        domain/CarValidators.h
        repository/CarRepository.cpp
        repository/CarRepository.h
        controller/CarController.cpp
        controller/CarController.h
        ui/UI.cpp
        ui/UI.h)
