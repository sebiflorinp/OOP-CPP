#include "CarRepository.h"

Car CarRepository::getCarByRegistrationNumber(const std::string& registrationNumber) {
    // find the car with the received registration
    for (auto & car : cars) {
        if (car.getRegistrationNumber() == registrationNumber) {
            return car;
        }
    }
    // throw an error if the car was not found
    throw std::exception();
}

const DynamicArray<Car>& CarRepository::getAllCars() const {
    return cars;
}

void CarRepository::addNewCar(Car newCar) {
    // check if there is already a Car with the registrationNumber of the received one.
    for (auto & car : cars) {
        if (car.getRegistrationNumber() == newCar.getRegistrationNumber()) {
            // throw an error because there is already another car with the registrationNumber of the received car
            throw std::exception();
        }
    }

    // add the new car
    cars.add(newCar);
}

void CarRepository::deleteCarByRegistrationNumber(const std::string& registrationNumber) {
    // find the car that needs to be deleted
    for (int i = 0; i < cars.size(); i++) {
        if (cars.get(i).getRegistrationNumber() == registrationNumber) {
            // delete the car
            cars.erase(i);
            return;
        }
    }

    // throw an error if no car was deleted
    throw std::exception();
}

void CarRepository::updateCarByRegistrationNumber(const std::string& registrationNumber, Car updatedCar) {
    // ensure that the update operation will not lead to multiple cars with the same registration number
    if (registrationNumber != updatedCar.getRegistrationNumber()) {
        for (auto & car : cars) {
            if (car.getRegistrationNumber() == updatedCar.getRegistrationNumber()) {
                // throw an error because the update will create multiple cars with the same registration number
                throw std::exception();
            }
        }
    }
    // find the car that will be updated
    for (auto & car : cars) {
        if (car.getRegistrationNumber() == registrationNumber) {
            car = updatedCar;
            return;
        }
    }

    // if no car was found throw an error
    throw  std::exception();
}