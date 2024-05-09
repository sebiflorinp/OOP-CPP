#include <cassert>
#include <fstream>
#include "CarControllerTests.h"
#include "../controller/CarController.h"
#include "../misc/Filters.h"
#include "../misc/SortingFunctions.h"
#include "../misc/Exceptions.h"

void CarControllerTests::testGetAllCars() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO456CD", "BBB", "BBB", "BBB");
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO456CD", "BBB", "BBB", "BBB");

    // Act
    std::vector<Car> actual = carController.getAllCars();

    // Assert
    assert(car1.compareCars(actual.at(0)));
    assert(car2.compareCars(actual.at(1)));
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
    std::vector<Car> actual = carController.filter("AAA", filterByProducer);

    // Assert
    assert(actual.size() == 1);
    assert(actual.at(0).getRegistrationNumber() == car1.getRegistrationNumber());
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
    std::vector<Car> actual = carController.sort(carController.getAllCars(), "ASC", sortCarsByRegistrationNumber);

    // Assert
    assert(actual.at(0).getRegistrationNumber() == car3.getRegistrationNumber());
    assert(actual.at(1).getRegistrationNumber() == car2.getRegistrationNumber());
    assert(actual.at(2).getRegistrationNumber() == car1.getRegistrationNumber());

}

void CarControllerTests::testCreateTypeReport() {
    // Arrange
    CarRepository carRepository = CarRepository();

    CarController carController = CarController(carRepository);
    Car car1 = Car("RO123AB", "AAA", "AAA", "AAA");
    Car car2 = Car("RO111BB", "BBB", "BBB", "BBB");
    Car car3 = Car("EN123BB", "CCC", "CCC", "CCC");
    Car car4 = Car("EN124BB", "CCC", "CCC", "CCC");

    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO111BB", "BBB", "BBB", "BBB");
    carController.addNewCar("EN123BB", "CCC", "CCC", "CCC");
    carController.addNewCar("EN124BB", "CCC", "CCC", "CCC");

    // Act
    std::unordered_map<std::string, TypeDTO> actual = carController.createTypeReport();

    // Assert
    assert(actual["AAA"].getType() == "AAA");
    assert(actual["AAA"].getCount() == 1);

    assert(actual["BBB"].getType() == "BBB");
    assert(actual["BBB"].getCount() == 1);

    assert(actual["CCC"].getType() == "CCC");
    assert(actual["CCC"].getCount() == 2);
}

void CarControllerTests::testLoadData() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);
    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");

    std::ofstream out("test.txt");
    out << "RO123AB AAA AAA AAA\n";
    out << "RO111BB BBB BBB BBB\n";
    out << "EN123BB CCC CCC CCC\n";
    out.close();

    // Act
    carController.loadData("test.txt");

    // Assert
    assert(carController.getAllCars().size() == 3);
    try {
        carController.findCarByRegistrationNumber("RO123AB");
        assert(true);
    } catch (CarNotFoundError) {
        assert(false);
    }

    try {
        carController.findCarByRegistrationNumber("RO111BB");
        assert(true);
    } catch (CarNotFoundError) {
        assert(false);
    }

    try {
        carController.findCarByRegistrationNumber("EN123BB");
        assert(true);
    } catch (CarNotFoundError) {
        assert(false);
    }
}

void CarControllerTests::testSaveData() {
    // Arrange
    CarRepository carRepository = CarRepository();
    CarController carController = CarController(carRepository);

    carController.addNewCar("RO123AB", "AAA", "AAA", "AAA");
    carController.addNewCar("RO111BB", "BBB", "BBB", "BBB");
    carController.addNewCar("EN123BB", "CCC", "CCC", "CCC");

    // Act
    carController.saveData("test.txt");

    // Assert
    std::ifstream in("test.txt");
    std::string registrationNumber, type, model, producer;
    for (auto car: carController.getAllCars()) {
        in >> registrationNumber >> type >> model >> producer;
        assert(car.getRegistrationNumber() == registrationNumber);
        assert(car.getType() == type);
        assert(car.getModel() == model);
        assert(car.getProducer() == producer);
    }
}


