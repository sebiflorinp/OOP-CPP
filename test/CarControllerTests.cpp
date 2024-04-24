#include <cassert>
#include "CarControllerTests.h"
#include "../controller/CarController.h"
#include "../misc/Filters.h"
#include "../misc/SortingFunctions.h"

void CarControllerTests::testGetAllCars() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO456CD", "BBB", "BBB", "BBB");
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO456CD", "BBB", "BBB", "BBB");

    // Act
    DynamicArray<Car> actual = carController.getAllCars();

    // Assert
    assert(car1.compareCars(actual.get(0)));
    assert(car2.compareCars(actual.get(1)));
}

void CarControllerTests::testFindCarByRegistrationNumber() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO111AB", "BBB", "BBB", "BBB");
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO111AB", "BBB", "BBB" , "BBB");

    // Act
    Car actual1 = carController.findCarByRegistrationNumber("RO123AB");
    Car actual2 = carController.findCarByRegistrationNumber("RO111AB");
    try {
        carController.findCarByRegistrationNumber("RO222CD");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    // Assert
    assert(car1.compareCars(actual1));
    assert(car2.compareCars(actual2));
}

void CarControllerTests::testAddCar() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");

    // Act
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");

    try {
        carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    // Assert
    assert(car1.compareCars(carController.findCarByRegistrationNumber("RO123AB")));
}

void CarControllerTests::testUpdateCarByRegistrationNumber() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO111BB", "BBB", "BBB", "BBB");
    Car car3 = Car("EN123BB", "CCC", "CCC", "CCC");
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO111BB", "BBB", "BBB", "BBB");

    // Act
    try {
        carController.updateCarByRegistrationNumber("RO123AB", "RO111BB", "AAA", "AAA", "AAA");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    try {
        carController.updateCarByRegistrationNumber("BG123BB", "EN123BB", "CCC", "CCC", "CCC");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    carController.updateCarByRegistrationNumber("RO123AB", "EN123BB", "CCC", "CCC", "CCC");
    // Assert
    assert(car3.compareCars(carController.findCarByRegistrationNumber("EN123BB")));
    assert(car2.compareCars(carController.findCarByRegistrationNumber("RO111BB")));
    try {
        carController.findCarByRegistrationNumber("RO123AB");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }
}

void CarControllerTests::testDeleteCarByRegistrationNumber() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO111BB", "BBB", "BBB", "BBB");
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO111BB", "BBB", "BBB", "BBB");

    // Act
    try {
        carController.deleteCarByRegistrationNumber("EN123AB");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    carController.deleteCarByRegistrationNumber("RO123AB");

    // Assert
    assert(car2.compareCars(carController.findCarByRegistrationNumber("RO111BB")));
    try {
        carController.findCarByRegistrationNumber("RO123AB");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }
}

void CarControllerTests::testFilter() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO111BB", "BBB", "BBB", "BBB");
    Car car3 = Car("EN123BB", "CCC", "CCC", "CCC");
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO111BB", "BBB", "BBB", "BBB");

    // Act
    DynamicArray<Car> actual = carController.filter("AAA", filterByProducer);

    // Assert
    assert(actual.size() == 1);
    assert(actual.get(0).getRegistrationNumber() == car1.getRegistrationNumber());
}

void CarControllerTests::testSort() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO111BB", "BBB", "BBB", "BBB");
    Car car3 = Car("EN123BB", "CCC", "CCC", "CCC");
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO111BB", "BBB", "BBB", "BBB");
    carController.addNewCar("EN123BB", "CCC", "CCC", "CCC");

    // Act
    DynamicArray<Car> actual = carController.sort(carController.getAllCars(), "ASC", sortCarsByRegistrationNumber);

    // Assert
    assert(actual.get(0).getRegistrationNumber() == car3.getRegistrationNumber());
    assert(actual.get(1).getRegistrationNumber() == car2.getRegistrationNumber());
    assert(actual.get(2).getRegistrationNumber() == car1.getRegistrationNumber());

}
