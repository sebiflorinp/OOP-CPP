#include <cassert>
#include "CarRepositoryTests.h"
#include "../domain/Car.h"
#include "../repository/CarRepository.h"

void CarRepositoryTests::testAddNewCar() {
    // Arrange
    Car car1 = Car("RO123AA", "AAA", "AAA", "AAA");
    Car car2 = Car("RO123BB", "VVV", "VVV", "VVV");
    Car car3 = Car("RO123AA", "BBB", "BBB", "BBB");
    CarRepository cars = CarRepository();
    cars.addNewCar(car1);

    // Act
    try {
        cars.addNewCar(car3);
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }

    try {
        cars.addNewCar(car2);
    } catch (...) {
        assert(false == true);
    }

    // Assert
    assert(car1.compareCars(cars.getCarByRegistrationNumber("RO123AA")));
    assert(car2.compareCars(cars.getCarByRegistrationNumber("RO123BB")));
}

void CarRepositoryTests::testGetCarByRegistrationNumber() {
    // Arrange
    Car car1 = Car("RO123AA", "AAA", "AAA", "AAA");
    Car car2 = Car("RO123BB", "VVV", "VVV", "VVV");
    CarRepository cars = CarRepository();
    cars.addNewCar(car1);
    cars.addNewCar(car2);

    // Act
    const Car actual1 = cars.getCarByRegistrationNumber("RO123AA");
    const Car actual2 = cars.getCarByRegistrationNumber("RO123BB");
    try {
        const Car actual3 = cars.getCarByRegistrationNumber("RO134AA");
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }

    // Assert
    assert(car1.compareCars(actual1));
    assert(car2.compareCars(actual2));
}

void CarRepositoryTests::testGetAllCars() {
    // Arrange
    Car car1 = Car("RO123AA", "AAA", "AAA", "AAA");
    Car car2 = Car("RO123BB", "VVV", "VVV", "VVV");
    CarRepository cars = CarRepository();
    cars.addNewCar(car1);
    cars.addNewCar(car2);

    // Act
    DynamicArray<Car> returnedCars = cars.getAllCars();

    // Assert
    assert(car1.compareCars(returnedCars.get(0)));
    assert(car2.compareCars(returnedCars.get(1)));
}

void CarRepositoryTests::testDeleteCarByRegistrationNumber() {
    // Arrange
    Car car1 = Car("RO123AA", "AAA", "AAA", "AAA");
    Car car2 = Car("RO123BB", "VVV", "VVV", "VVV");
    CarRepository cars = CarRepository();
    cars.addNewCar(car1);
    cars.addNewCar(car2);

    // Act
    try {
        cars.deleteCarByRegistrationNumber("RO123BN");
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }

    cars.deleteCarByRegistrationNumber("RO123AA");

    // Assert
    try {
        cars.getCarByRegistrationNumber("RO123AA");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }
    assert(car2.compareCars(cars.getCarByRegistrationNumber("RO123BB")));
}

void CarRepositoryTests::testUpdateCarByRegistrationNumber() {
    // Arrange
    Car car1 = Car("RO123AA", "AAA", "AAA", "AAA");
    Car car2 = Car("RO123BB", "VVV", "VVV", "VVV");
    Car newCar1= Car("EN123AA", "BBB", "BBB", "BBB");
    CarRepository cars = CarRepository();
    cars.addNewCar(car1);
    cars.addNewCar(car2);

    // Act
    try {
        cars.updateCarByRegistrationNumber("RO123MM", newCar1);
        assert(true == false);
    } catch (...) {
        assert(true == true)
;
    }

    try {
        cars.updateCarByRegistrationNumber(car1.getRegistrationNumber(), car2);
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }

    cars.updateCarByRegistrationNumber("RO123AA", newCar1);

    // Assert
    try {
        cars.getCarByRegistrationNumber("RO123AA");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    assert(newCar1.compareCars(cars.getCarByRegistrationNumber("EN123AA")));

}