#include "tests.h"
#include "CarValidatorsTests.h"
#include "CarTests.h"
#include "CarRepositoryTests.h"
#include "CarControllerTests.h"

void runAllTests() {
    // car validators tests
    CarValidatorsTests carValidatorsTests = CarValidatorsTests();
    carValidatorsTests.testValidateRegistrationNumber();
    carValidatorsTests.testValidateType();
    carValidatorsTests.testValidateModel();
    carValidatorsTests.testValidateProducer();

    // car constructor, setters and getters tests
    CarTests carTests = CarTests();
    carTests.testConstructor();
    carTests.testGetters();
    carTests.testSetters();
    carTests.testEquality();

    // car repository tests
    CarRepositoryTests carRepositoryTests = CarRepositoryTests();
    carRepositoryTests.testAddNewCar();
    carRepositoryTests.testDeleteCarByRegistrationNumber();
    carRepositoryTests.testGetCarByRegistrationNumber();
    carRepositoryTests.testUpdateCarByRegistrationNumber();
    carRepositoryTests.testGetAllCars();

    // car controller tests
    CarControllerTests carControllerTests = CarControllerTests();
    carControllerTests.testAddCar();
    carControllerTests.testFindCarByRegistrationNumber();
    carControllerTests.testGetAllCars();
    carControllerTests.testUpdateCarByRegistrationNumber();
    carControllerTests.testDeleteCarByRegistrationNumber();
}

