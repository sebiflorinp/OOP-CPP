#include "CarController.h"

CarController::CarController(const CarRepository& carRepository) {
    this->carRepository = carRepository;
}

void CarController::addNewCar(
        const std::string& registrationNumber,
        const std::string& type,
        const std::string& model,
        const std::string& producer
        ) {
    // create new car object and try to add it in the repository
    Car newCar = Car(registrationNumber, producer, model, type);
    carRepository.addNewCar(newCar);
}

Car CarController::findCarByRegistrationNumber(const std::string& registrationNumber) {
    // return the car with the given registrationNumber or throw an error
    return this->carRepository.getCarByRegistrationNumber(registrationNumber);
}

const std::vector<Car>& CarController::getAllCars() {
    return this->carRepository.getAllCars();
}

void CarController::deleteCarByRegistrationNumber(const std::string& registrationNumber) {
    // deletes the car with the given registrationNumber or throw an error if there is no car with the given registrationNumber
    this->carRepository.deleteCarByRegistrationNumber(registrationNumber);
}

void CarController::updateCarByRegistrationNumber(const std::string& registrationNumber, const std::string& newRegistrationNumber, const std::string& type, const std::string& model, const std::string& producer) {
    // Create the updated car
    Car updatedCar = Car(newRegistrationNumber, producer, model, type);
    // Updates the car
    this->carRepository.updateCarByRegistrationNumber(registrationNumber, updatedCar);
}



