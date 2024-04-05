#include <cassert>
#include "CarTests.h"
#include "../domain/Car.h"

void CarTests::testConstructor() {
    // check if the constructor doesn't break when it receives valid data
    try {
        Car car = Car("RO567AA", "ASFB", "AERT", "AFGHJ");
    } catch (...) {
        assert(false == true);
    }

    // check if the constructor breaks when it receives empty fields
    try {
        Car car = Car("", "", "", "");
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }

    // check if the constructor breaks when it receives an invalid registrationNumber
    try {
        Car car = Car("RO56AS", "ASDF", "asdgf", "fdg");
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }
}

void CarTests::testGetters() {
    // Arrange
    const std::string registrationNumber = "RO124AE";
    const std::string type = "ASDF";
    const std::string model = "QWER";
    const std::string producer = "QWERR";
    Car car = Car(registrationNumber, producer, model, type);

    // Act
    const std::string actual1 = car.getRegistrationNumber();
    const std::string actual2 = car.getProducer();
    const std::string actual3 = car.getType();
    const std::string actual4 = car.getModel();

    // Assert
    assert(actual1 == registrationNumber);
    assert(actual2 == producer);
    assert(actual3 == type);
    assert(actual4 == model);
}

void CarTests::testSetters() {
    // Arrange
    const std::string validRegistrationNumber = "RO124AE";
    const std::string validType = "ASDF";
    const std::string validModel = "QWER";
    const std::string validProducer = "QWERR";
    const std::string invalidRegistrationNumber = "";
    const std::string invalidType = "";
    const std::string invalidModel = "";
    const std::string invalidProducer = "";
    Car car = Car("RO345AA", "AAAA", "AAAA", "AAAA");

    // Act
    // try setting invalid data
    try {
        car.setRegistrationNumber(invalidRegistrationNumber);
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    try {
        car.setModel(invalidModel);
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    try {
        car.setType(invalidType);
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }

    try {
        car.setProducer(invalidProducer);
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }

    // set valid data
    car.setRegistrationNumber(validRegistrationNumber);
    car.setProducer(validProducer);
    car.setType(validType);
    car.setModel(validModel);

    // Assert
    assert(car.getRegistrationNumber() == validRegistrationNumber);
    assert(car.getProducer() == validProducer);
    assert(car.getModel() == validModel);
    assert(car.getType() == validType);
}

void CarTests::testEquality() {
    // Arrage
    Car car1 = Car("RO123AA", "AAA", "AAA", "AAA");
    Car car2 = Car("RO123AA", "AAA", "AAA", "AAA");
    Car car3 = Car("RO122AA", "AAA", "AAA", "AAA");

    // Act
    const bool actual1 = car1.compareCars(car2);
    const bool actual2 = car1.compareCars(car3);

    // Assert
    assert(actual1 == true);
    assert(actual2 == false);
}