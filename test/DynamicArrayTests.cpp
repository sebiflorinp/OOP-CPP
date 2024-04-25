#include <cassert>
#include <iostream>
#include "DynamicArrayTests.h"
#include "../domain/Car.h"
#include "../misc/DynamicArray.h"

void DynamicArrayTests::testDynamicArray() {
    // Arrange
    Car car1 = Car("RO123AA", "Dacia", "A12", "Regular");
    Car car2 = Car("RO234AA", "Dacia", "A45", "Sports");
    Car car3 = Car("RO123GG", "Mercedes", "A45", "Regular");
    DynamicArray<Car> cars;

    // Act
    cars.add(car1);
    int actual1 = cars.size();

    // Assert
    assert(actual1 == 1);
    assert(cars.get(0).getRegistrationNumber() == car1.getRegistrationNumber());

    // Act
    cars.erase(0);
    int actual2 = cars.size();

    // Assert
    assert(actual2 == 0);

    // Act
    cars.add(car1);
    cars.add(car2);
    cars.add(car3);
    Car actual3 = cars.get(1);

    // Assert
    assert(actual3.getRegistrationNumber() == car2.getRegistrationNumber());

    // Act
    DynamicArray<Car> cars1;
    for (auto car: cars) {
        cars1.add(car);
    }

    // Assert
    assert(cars1.size() == 3);
    assert(cars1.get(0).getRegistrationNumber() == cars.get(0).getRegistrationNumber());
    assert(cars1.get(1).getRegistrationNumber() == cars.get(1).getRegistrationNumber());
    assert(cars1.get(2).getRegistrationNumber() == cars.get(2).getRegistrationNumber());

    // Act
    for (int i = 0; i < cars.size(); ++i) {
        cars.set(i, car1);
    }

    // Assert
    assert(car1.getRegistrationNumber() == cars.get(0).getRegistrationNumber());
    assert(car1.getRegistrationNumber() == cars.get(1).getRegistrationNumber());
    assert(car1.getRegistrationNumber() == cars.get(2).getRegistrationNumber());

    // Act
    cars1 = cars;

    // Assert
    assert(car1.getRegistrationNumber() == cars1.get(0).getRegistrationNumber());
    assert(car1.getRegistrationNumber() == cars1.get(1).getRegistrationNumber());
    assert(car1.getRegistrationNumber() == cars1.get(2).getRegistrationNumber());

    // Act
    cars.erase(0);
    cars.erase(0);

    // Assert
    assert(cars.size() == 1);
}
