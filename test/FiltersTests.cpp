#include <cassert>
#include "FiltersTests.h"
#include "../repository/CarRepository.h"
#include "../controller/CarController.h"
#include "../misc/Filters.h"

void FiltersTests::testFilterByProducer() {
    // Arrange
    std::vector<Car> cars;
    Car car1 = Car("RO123AA", "Dacia", "12AA", "Regular");
    Car car2 = Car("EN123RR", "Dacia", "23AA", "Regular");
    Car car3 = Car("DE123VV", "Mercedes", "66FF", "Sports");
    Car car4 = Car("RO444WW", "Dacia", "11DD", "Sports");
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);
    cars.push_back(car4);

    // Act
    std::vector<Car> actual = filterByProducer(cars, "Mercedes");

    // Assert
    assert(actual.size() == 1);
    Car actualCar = actual.at(0);
    assert(actualCar.getRegistrationNumber() == car3.getRegistrationNumber());
}

void FiltersTests::testFilterByType() {
    // Arrange
    std::vector<Car> cars;
    Car car1 = Car("RO123AA", "Dacia", "12AA", "Regular");
    Car car2 = Car("EN123RR", "Dacia", "23AA", "Regular");
    Car car3 = Car("DE123VV", "Mercedes", "66FF", "Sports");
    Car car4 = Car("RO444WW", "Dacia", "11DD", "Sports");
    cars.push_back(car1);
    cars.push_back(car2);
    cars.push_back(car3);
    cars.push_back(car4);

    // Act
    std::vector<Car> actual = filterByType(cars, "Sports");

    // Assert
    assert(actual.size() == 2);
    Car actualCar1 = actual.at(0);
    Car actualCar2 = actual.at(1);
    assert(actualCar1.getRegistrationNumber() == car3.getRegistrationNumber());
    assert(actualCar2.getRegistrationNumber() == car4.getRegistrationNumber());

}
