#include "tests.h"
#include "CarValidatorsTests.h"
#include "CarTests.h"
#include "CarRepositoryTests.h"
#include "CarControllerTests.h"
#include "../misc/DynamicArray.h"
#include "FiltersTests.h"
#include "SortingFunctionsTests.h"
#include "DynamicArrayTests.h"
#include "GenericExceptionTests.h"
#include "CarsToWashControllerTests.h"
#include "TypeDTOTests.h"
#include "UndoTests.h"

void testAll();

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
    carControllerTests.testFilter();
    carControllerTests.testSort();
    carControllerTests.testCreateTypeReport();
    carControllerTests.testCreateTypeReport();
    carControllerTests.testLoadData();
    carControllerTests.testSaveData();

    // Filters tests
    FiltersTests filtersTests = FiltersTests();
    filtersTests.testFilterByProducer();
    filtersTests.testFilterByType();

    // SortingFunctions tests
    SortingFunctionsTests sortingFunctionsTests = SortingFunctionsTests();
    sortingFunctionsTests.testCompareTypes();
    sortingFunctionsTests.testCompareRegistrationNumbers();
    sortingFunctionsTests.testCompareProducersAndModels();
    sortingFunctionsTests.testSortCarsByType();
    sortingFunctionsTests.testSortCarsByRegistrationNumber();
    sortingFunctionsTests.testSortCarsByProducerAndModel();

    // DynamicArray tests
    DynamicArrayTests dynamicArrayTests = DynamicArrayTests();
    dynamicArrayTests.testDynamicArray();

    // GenericException tests
    GenericExceptionTests genericExceptionTests = GenericExceptionTests();
    genericExceptionTests.testGetErrorMessage();

    // CarsToWashController tests
    CarsToWashControllerTests carsToWashControllerTests = CarsToWashControllerTests();
    carsToWashControllerTests.TestGetAllCars();
    carsToWashControllerTests.TestAddCarToWashRepository();
    carsToWashControllerTests.TestEmptyRepository();
    carsToWashControllerTests.TestAddRandomCars();
    carsToWashControllerTests.TestExportCarsToWash();

    // TypeDTO tests
    TypeDTOTests typeDTOTests = TypeDTOTests();
    typeDTOTests.testTypeDTO();

    // Undo tests
    UndoTests undoTests = UndoTests();
    undoTests.testUndo();
    undoTests.testUndoAdd();
    undoTests.testUndoDelete();
    undoTests.testUndoUpdate();
}



