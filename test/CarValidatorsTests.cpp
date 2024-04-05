#include <string>
#include <cassert>
#include "CarValidatorsTests.h"
#include "../domain/CarValidators.h"

void CarValidatorsTests::testValidateRegistrationNumber() {
    // Arrange
    CarValidators validators = CarValidators();
    const std::string validRegistrationNumber = "RO57AAA";
    const std::string invalidRegistrationNumber1 = "";
    const std::string invalidRegistrationNumber2 = "ROCJ12345";

    // Act
    try {
        validators.validateRegistrationNumber(validRegistrationNumber);
    }
    catch (...) {
        assert(true == false);
    }

    try {
        validators.validateRegistrationNumber(invalidRegistrationNumber1);
        assert(true == false);
    } catch(...) {
        assert(true == true);
    }

    try {
        validators.validateRegistrationNumber(invalidRegistrationNumber2);
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }
}

void CarValidatorsTests::testValidateProducer() {
    // Arrange
    CarValidators validators = CarValidators();
    const std::string validProducer = "Dacia";
    const std::string invalidProducer = "";

    // Act
    try {
        validators.validateProducer(validProducer);
    } catch (...) {
        assert(true == false);
    }

    try {
        validators.validateProducer(invalidProducer);
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }
}

void CarValidatorsTests::testValidateType() {
    // Arrange
    CarValidators validators = CarValidators();
    const std::string validType = "Sports";
    const std::string invalidType = "";

    // Act
    try {
        validators.validateType(validType);
    } catch (...) {
        assert(true == false);
    }

    try {
        validators.validateType(invalidType);
        assert(true == false);
    } catch (...) {
        assert(true == true);
    }
}

void CarValidatorsTests::testValidateModel() {
    // Arrange
    CarValidators validators = CarValidators();
    const std::string validModel = "ABC";
    const std::string invalidModel = "";

    // Act
    try {
        validators.validateModel(validModel);
    } catch (...) {
        assert(true == false);
    }

    try {
        validators.validateModel(invalidModel);
        assert(false == true);
    } catch (...) {
        assert(true == true);
    }
}

