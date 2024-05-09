#include <cassert>
#include "UndoTests.h"
#include "../repository/CarRepository.h"
#include "../controller/CarController.h"
#include "../misc/Exceptions.h"

void UndoTests::testUndoAdd() {
    // Arrange
    CarRepository repo;
    CarController carController(repo);
    Car car1("RO123AA", "BMW", "X5", "Luxury");
    Car car2("RO124AA", "Audi", "A4", "Sport");
    carController.addNewCar("RO123AA", "BMW", "X5", "Luxury");
    carController.addNewCar("RO124AA", "Audi", "A4", "Sport");

    // Act
    carController.undo();

    // Assert
    assert(carController.getAllCars().size() == 1);
    assert(carController.getAllCars()[0].getRegistrationNumber() == car1.getRegistrationNumber());
}

void UndoTests::testUndoDelete() {
    // Arrange
    CarRepository repo;
    CarController carController(repo);
    Car car1("RO123AA", "BMW", "X5", "Luxury");
    Car car2("RO124AA", "Audi", "A4", "Sport");
    carController.addNewCar("RO123AA", "BMW", "X5", "Luxury");
    carController.addNewCar("RO124AA", "Audi", "A4", "Sport");

    // Act
    carController.deleteCarByRegistrationNumber("RO123AA");
    carController.undo();

    // Assert
    assert(carController.getAllCars().size() == 2);
    assert(carController.getAllCars()[0].getRegistrationNumber() == car2.getRegistrationNumber());
    assert(carController.getAllCars()[1].getRegistrationNumber() == car1.getRegistrationNumber());
}

void UndoTests::testUndoUpdate() {
    // Arrange
    CarRepository repo;
    CarController carController(repo);
    Car car1("RO123AA", "BMW", "X5", "Luxury");
    Car car2("RO124AA", "Audi", "A4", "Sport");
    carController.addNewCar("RO123AA", "BMW", "X5", "Luxury");
    carController.addNewCar("RO124AA", "Audi", "A4", "Sport");

    // Act
    carController.updateCarByRegistrationNumber("RO123AA", "EN125AA", "BMW", "X5", "Luxury");
    carController.undo();

    // Assert
    assert(carController.getAllCars().size() == 2);
    assert(carController.getAllCars()[0].getRegistrationNumber() == car1.getRegistrationNumber());
    assert(carController.getAllCars()[1].getRegistrationNumber() == car2.getRegistrationNumber());
}

void UndoTests::testUndo() {
    // Arrange
    CarRepository repo;
    CarController carController(repo);
    Car car1("RO123AA", "BMW", "X5", "Luxury");
    Car car2("RO124AA", "Audi", "A4", "Sport");
    carController.addNewCar("RO123AA", "BMW", "X5", "Luxury");
    carController.addNewCar("RO124AA", "Audi", "A4", "Sport");

    // Act
    carController.undo();
    carController.undo();

    // Assert
    try {
        carController.undo();
        assert(false);
    } catch (UndoError) {
        assert(true);
    }

    assert(carController.getAllCars().size() == 0);
}
