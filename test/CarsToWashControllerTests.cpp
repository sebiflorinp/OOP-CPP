#include <cassert>
#include <fstream>
#include <iostream>
#include "CarsToWashControllerTests.h"
#include "../repository/CarRepository.h"
#include "../controller/CarsToWashController.h"
#include "../misc/Exceptions.h"

void CarsToWashControllerTests::TestGetAllCars() {
    // Arrange
    CarRepository carRepository;
    Car car1("RO123AA", "Dacia", "AAAA", "Sports");
    Car car2("EN123BB", "Ferrari", "AS12", "Sports");
    Car car3("DE123AA", "BMW", "BB55", "Luxury");

    carRepository.addNewCar(car1);
    carRepository.addNewCar(car2);
    carRepository.addNewCar(car3);

    CarsToWashController carsToWashController(carRepository);
    carsToWashController.addCarToWashRepository("RO123AA");
    carsToWashController.addCarToWashRepository("EN123BB");
    carsToWashController.addCarToWashRepository("DE123AA");

    // Act
    std::vector<Car> cars = carsToWashController.GetAllCars();

    // Assert
    assert(cars.size() == 3);

    assert(cars[0].getRegistrationNumber() == car1.getRegistrationNumber());
    assert(cars[1].getRegistrationNumber() == car2.getRegistrationNumber());
    assert(cars[2].getRegistrationNumber() == car3.getRegistrationNumber());

}

void CarsToWashControllerTests::TestAddCarToWashRepository() {
    // Arrange
    CarRepository carRepository;
    Car car1("RO123AA", "Dacia", "AAAA", "Sports");
    Car car2("EN123BB", "Ferrari", "AS12", "Sports");
    Car car3("DE123AA", "BMW", "BB55", "Luxury");

    carRepository.addNewCar(car1);
    carRepository.addNewCar(car2);
    carRepository.addNewCar(car3);

    CarsToWashController carsToWashController(carRepository);

    // Act
    carsToWashController.addCarToWashRepository("RO123AA");
    carsToWashController.addCarToWashRepository("EN123BB");
    carsToWashController.addCarToWashRepository("DE123AA");

    // Assert
    try {
        carsToWashController.addCarToWashRepository("RO123AA");
    } catch (DuplicateDataError) {
        assert(true);
    }

    try {
        carsToWashController.addCarToWashRepository("EN124BB");
    } catch (CarNotFoundError) {
        assert(true);
    }

    std::vector<Car> cars = carsToWashController.GetAllCars();

    assert(cars[0].getRegistrationNumber() == car1.getRegistrationNumber());
    assert(cars[1].getRegistrationNumber() == car2.getRegistrationNumber());
    assert(cars[2].getRegistrationNumber() == car3.getRegistrationNumber());
}

void CarsToWashControllerTests::TestEmptyRepository() {
    // Arrange
    CarRepository carRepository;
    Car car1("RO123AA", "Dacia", "AAAA", "Sports");
    Car car2("EN123BB", "Ferrari", "AS12", "Sports");
    Car car3("DE123AA", "BMW", "BB55", "Luxury");

    carRepository.addNewCar(car1);
    carRepository.addNewCar(car2);
    carRepository.addNewCar(car3);

    CarsToWashController carsToWashController(carRepository);
    carsToWashController.addCarToWashRepository("RO123AA");
    carsToWashController.addCarToWashRepository("EN123BB");
    carsToWashController.addCarToWashRepository("DE123AA");

    // Act
    carsToWashController.emptyRepository();

    // Assert
    std::vector<Car> cars = carsToWashController.GetAllCars();
    assert(cars.empty());
}

void CarsToWashControllerTests::TestAddRandomCars() {
    // Arrange
    CarRepository carRepository;
    Car car1("RO123AA", "Dacia", "AAAA", "Sports");
    Car car2("EN123BB", "Ferrari", "AS12", "Sports");
    Car car3("DE123AA", "BMW", "BB55", "Luxury");

    carRepository.addNewCar(car1);
    carRepository.addNewCar(car2);
    carRepository.addNewCar(car3);

    CarsToWashController carsToWashController(carRepository);
    carsToWashController.addCarToWashRepository("RO123AA");

    // Act
    carsToWashController.addRandomCars(2);

    // Assert
    try {
        carsToWashController.addRandomCars(4);
        assert(false);
    } catch (AddRandomCarsError) {
        assert(true);
    }

    try {
        carsToWashController.addRandomCars(1);
        assert(false);
    } catch (AddRandomCarsError) {
        assert(true);
    }

    std::vector<Car> cars = carsToWashController.GetAllCars();
    assert(cars.size() == 2);
}

void CarsToWashControllerTests::TestExportCarsToWash() {
    // Arrange
    CarRepository carRepository;
    Car car1("RO123AA", "Dacia", "AAAA", "Sports");
    Car car2("EN123BB", "Ferrari", "AS12", "Sports");
    Car car3("DE123AA", "BMW", "BB55", "Luxury");

    carRepository.addNewCar(car1);
    carRepository.addNewCar(car2);
    carRepository.addNewCar(car3);

    CarsToWashController carsToWashController(carRepository);
    carsToWashController.addCarToWashRepository("RO123AA");
    carsToWashController.addCarToWashRepository("EN123BB");
    carsToWashController.addCarToWashRepository("DE123AA");
    carRepository.deleteCarByRegistrationNumber("EN123BB");

    std::string exportNameHTML = "htmlTest";
    std::string exportNameCSV = "csvTest";

    // Act
    carsToWashController.exportCarsToWash("HTML", exportNameHTML);
    carsToWashController.exportCarsToWash("CSV", exportNameCSV);

    // Assert
    try {
        carsToWashController.exportCarsToWash("PDF", exportNameHTML);
        assert(false);
    } catch (InvalidExportFormatError) {
        assert(true);
    }

    std::ifstream htmlFile("htmlTest.html");
    std::string content;
    getline(htmlFile, content);
    assert(content == "<!DOCTYPE html><html><head><title>" + exportNameHTML + "</title></head><body><table><tr><th>Registration number</th><th>Type</th><th>Model</th><th>Producer</th></tr>");
    for (auto car: carsToWashController.GetAllCars()) {
        htmlFile >> content;
        assert(content == "<tr><td>" + car.getRegistrationNumber() + "</td><td>" + car.getType() + "</td><td>" + car.getModel() + "</td><td>" + car.getProducer() + "</td></tr>");
    }
    htmlFile >> content;
    assert(content == "</table></body></html>");

    std::ifstream csvFile("csvTest.csv");
    for (auto car: carsToWashController.GetAllCars()) {
        csvFile >> content;
        assert(content == car.getRegistrationNumber() + "," + car.getType() + "," + car.getModel() + "," + car.getProducer());
    }
}
