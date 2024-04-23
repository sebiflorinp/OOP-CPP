#include <string>
#include <cassert>
#include "SortingFunctionsTests.h"
#include "../misc/SortingFunctions.h"

void SortingFunctionsTests::testCompareTypes() {
    // Arrange
    Car car1 = Car("RO123AA", "Dacia", "A12", "Regular");
    Car car2 = Car("RO234AA", "Dacia", "A45", "Sports");

    // Act
    int actual1 = compareTypes(car1, car2, "ASC");
    int actual2 = compareTypes(car2, car1, "ASC");
    int actual3 = compareTypes(car1, car1, "ASC");
    int actual4 = compareTypes(car2, car1, "DESC");

    // Assert
    assert(actual1 == 1);
    assert(actual2 == -1);
    assert(actual3 == 0);
    assert(actual4 == 1);
}

void SortingFunctionsTests::testCompareRegistrationNumbers() {
    // Arrange
    Car car1 = Car("RO123AA", "Dacia", "A12", "Regular");
    Car car2 = Car("RO234AA", "Dacia", "A45", "Sports");

    // Act
    int actual1 = compareRegistrationNumbers(car1, car2, "ASC");
    int actual2 = compareRegistrationNumbers(car2, car1, "ASC");
    int actual3 = compareRegistrationNumbers(car1, car1, "ASC");
    int actual4 = compareRegistrationNumbers(car2, car1, "DESC");

    // Assert
    assert(actual1 == 1);
    assert(actual2 == -1);
    assert(actual3 == 0);
    assert(actual4 == 1);
}

void SortingFunctionsTests::testCompareProducersAndModels() {
    // Arrange
    Car car1 = Car("RO123AA", "Dacia", "A12", "Regular");
    Car car2 = Car("RO234AA", "Dacia", "A45", "Sports");
    Car car3 = Car("RO123GG", "Mercedes", "A45", "Regular");

    // Act
    int actual1 = compareProducersAndModels(car1, car3, "ASC");
    int actual2 = compareProducersAndModels(car3, car1, "ASC");
    int actual3 = compareProducersAndModels(car1, car2, "ASC");
    int actual4 = compareProducersAndModels(car2, car1, "ASC");
    int actual5 = compareProducersAndModels(car1, car1, "ASC");
    int actual6 = compareProducersAndModels(car1, car3, "DESC");

    // Assert
    assert(actual1 == 1);
    assert(actual2 == -1);
    assert(actual3 == 1);
    assert(actual4 == -1);
    assert(actual5 == 0);
    assert(actual6 == -1);
}

void SortingFunctionsTests::testSortCarsByType() {
    // Arrange
    Car car1 = Car("RO123AA", "Dacia", "A12", "Regular");
    Car car2 = Car("RO234AA", "Dacia", "A45", "Sports");
    DynamicArray<Car> cars;
    cars.add(car1);
    cars.add(car2);

    // Act
    DynamicArray<Car> actual = sortCarsByType(cars, "DESC");

    // Assert
    assert(actual.get(0).getRegistrationNumber() == car2.getRegistrationNumber());
    assert(actual.get(1).getRegistrationNumber() == car1.getRegistrationNumber());
}

void SortingFunctionsTests::testSortCarsByRegistrationNumber() {
    // Arrange
    Car car1 = Car("RO123AA", "Dacia", "A12", "Regular");
    Car car2 = Car("RO234AA", "Dacia", "A45", "Sports");
    DynamicArray<Car> cars;
    cars.add(car1);
    cars.add(car2);

    // Act
    DynamicArray<Car> actual = sortCarsByRegistrationNumber(cars, "DESC");

    // Assert
    assert(actual.get(0).getRegistrationNumber() == car2.getRegistrationNumber());
    assert(actual.get(1).getRegistrationNumber() == car1.getRegistrationNumber());
}

void SortingFunctionsTests::testSortCarsByProducerAndModel() {
    // Arrange
    Car car1 = Car("RO123AA", "Dacia", "A12", "Regular");
    Car car2 = Car("RO234AA", "Dacia", "A45", "Sports");
    Car car3 = Car("RO123GG", "Mercedes", "A45", "Regular");
    DynamicArray<Car> cars;
    cars.add(car1);
    cars.add(car2);
    cars.add(car3);
    // Act
    DynamicArray<Car> actual = sortCarsByProducerAndModel(cars, "DESC");

    // Assert
    assert(actual.get(0).getRegistrationNumber() == car3.getRegistrationNumber());
    assert(actual.get(1).getRegistrationNumber() == car2.getRegistrationNumber());
    assert(actual.get(2).getRegistrationNumber() == car1.getRegistrationNumber());
}