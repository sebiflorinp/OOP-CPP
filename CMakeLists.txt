cmake_minimum_required(VERSION 3.27)
project(cpplab)

set(CMAKE_CXX_STANDARD 17 CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

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
        ui/UI.h
        test/CarValidatorsTests.cpp
        test/CarValidatorsTests.h
        test/tests.cpp
        test/tests.h
        test/CarTests.cpp
        test/CarTests.h
        test/CarRepositoryTests.cpp
        test/CarRepositoryTests.h
        test/CarControllerTests.cpp
        test/CarControllerTests.h
        misc/DynamicArray.h
        misc/Filters.cpp
        misc/Filters.h
        misc/SortingFunctions.cpp
        misc/SortingFunctions.h
        test/FiltersTests.cpp
        test/FiltersTests.h
        test/SortingFunctionsTests.cpp
        test/SortingFunctionsTests.h
        test/DynamicArrayTests.cpp
        test/DynamicArrayTests.h
        misc/Exceptions.cpp
        misc/Exceptions.h
        misc/Exceptions.cpp
        test/GenericExceptionTests.cpp
        test/GenericExceptionTests.h
        controller/CarsToWashController.cpp
        controller/CarsToWashController.h
        misc/Utils.cpp
        misc/Utils.h
        test/CarstToWashControllerTests.cpp
        test/CarstToWashControllerTests.h
        domain/TypeDTO.h
        domain/TypeDTO.cpp
        test/TypeDTOTests.cpp
        test/TypeDTOTests.h)
