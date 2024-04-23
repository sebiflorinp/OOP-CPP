#include "Filters.h"

DynamicArray<Car> filterByProducer(const DynamicArray<Car>& cars, const std::string& producer) {
    DynamicArray<Car> result;
    for (auto car: cars) {
        if (car.getProducer() == producer) {
            result.add(car);
        }
    }

    return result;
}

DynamicArray<Car> filterByType(const DynamicArray<Car>& cars, const std::string& type) {
    DynamicArray<Car> result;
    for (auto car: cars) {
        if (car.getType() == type) {
            result.add(car);
        }
    }

    return result;
}