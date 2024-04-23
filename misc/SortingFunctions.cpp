#include "SortingFunctions.h"
#include "../domain/Car.h"
#include "DynamicArray.h"

DynamicArray<Car> sortCarsByRegistrationNumber(DynamicArray<Car> cars, const std::string& sortingOrder) {
    for (int i = 0; i < cars.size() - 1; ++i) {
        for (int j = i + 1; j < cars.size(); ++j) {
            if (compareRegistrationNumbers(cars.get(i), cars.get(j), sortingOrder) == -1) {
                Car aux = cars.get(i);
                cars.set(i, cars.get(j));
                cars.set(j, aux);
            }
        }
    }
    return cars;
}

DynamicArray<Car> sortCarsByType(DynamicArray<Car> cars, const std::string& sortingOrder) {
    for (int i = 0; i < cars.size() - 1; ++i) {
        for (int j = i + 1; j < cars.size(); ++j) {
            if (compareTypes(cars.get(i), cars.get(j), sortingOrder) == -1) {
                Car aux = cars.get(i);
                cars.set(i, cars.get(j));
                cars.set(j, aux);
            }
        }
    }
    return cars;
}

DynamicArray<Car> sortCarsByProducerAndModel(DynamicArray<Car> cars, const std::string& sortingOrder) {
    for (int i = 0; i < cars.size() - 1; ++i) {
        for (int j = i + 1; j < cars.size(); ++j) {
            if (compareProducersAndModels(cars.get(i), cars.get(j), sortingOrder) == -1) {
                Car aux = cars.get(i);
                cars.set(i, cars.get(j));
                cars.set(j, aux);
            }
        }
    }
    return cars;
}

int compareRegistrationNumbers(Car& firstCar,Car& secondCar,const std::string& sortingOrder) {
    if (sortingOrder == "ASC") {
        if (firstCar.getRegistrationNumber() < secondCar.getRegistrationNumber()) {
            return 1;
        } else if (firstCar.getRegistrationNumber() > secondCar.getRegistrationNumber()) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return compareRegistrationNumbers(firstCar, secondCar, "ASC") * -1;
    }
}

int compareTypes(Car& firstCar, Car& secondCar, const std::string& sortingOrder) {
    if (sortingOrder == "ASC") {
        if (firstCar.getType() < secondCar.getType()) {
            return 1;
        } else if (firstCar.getType() > secondCar.getType()) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return compareTypes(firstCar, secondCar, "ASC") * -1;
    }
}

int compareProducersAndModels(Car& firstCar,Car& secondCar,const std::string& sortingOrder) {
    if (sortingOrder == "ASC") {
        if (firstCar.getProducer() < secondCar.getProducer()) {
            return 1;
        } else if (firstCar.getProducer() > secondCar.getProducer()) {
            return -1;
        } else {
            if (firstCar.getModel() < secondCar.getModel()) {
                return 1;
            } else if (firstCar.getModel() > secondCar.getModel()) {
                return -1;
            } else {
                return 0;
            }
        }
    } else {
        return compareProducersAndModels(firstCar, secondCar, "ASC") * -1;
    }
}

