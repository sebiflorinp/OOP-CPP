#include "CarController.h"
#include "../domain/TypeDTO.h"

#include <utility>

CarController::CarController(CarRepository& carRepository): carRepository(carRepository) {}

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

std::vector<Car> CarController::filter(std::string toEqual,std::vector<Car> (*filterByCriteria)(const std::vector<Car>&,const std::string&)) {
    return filterByCriteria(carRepository.getAllCars(), toEqual);
}

std::vector<Car>
CarController::sort(const std::vector<Car> & cars, const std::string& sortingOrder, std::vector<Car> (*sortByCriteria)(std::vector<Car>, const std::string&)) {
    return sortByCriteria(cars, sortingOrder);
}

std::unordered_map<std::string, TypeDTO> CarController::createTypeReport() {
    // Use a map to store the types of cars and their frequency
    std::unordered_map<std::string, int> typeReportWithoutDTO;
    for (auto car: carRepository.getAllCars()) {
        typeReportWithoutDTO[car.getType()]++;
    }

    // Create a map with TypeDTOs
    std::unordered_map<std::string, TypeDTO> typeReportWithDTO;
    for (auto pair: typeReportWithoutDTO) {
        typeReportWithDTO[pair.first] = TypeDTO(pair.first, pair.second);

    }
    return typeReportWithDTO;
}


