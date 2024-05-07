#include <iostream>
#include "test/tests.h"
#include "controller/CarController.h"
#include "ui/UI.h"
#include "misc/DynamicArray.h"

int main() {

    // Create repository
    CarRepository carRepository = CarRepository();

    // Create Controller
    CarController carController = CarController(carRepository);
    CarsToWashController carsToWashController = CarsToWashController(carRepository);

    // Add some cars for testing purposes
    carController.addNewCar("RO123AA", "Regular", "12AA", "Dacia");
    carController.addNewCar("EN123RR", "Regular", "23AA", "Dacia");
    carController.addNewCar("DE123VV", "Sports", "66FF", "Mercedes");
    carController.addNewCar("RO444WW", "Sports", "11DD", "Dacia");
    carController.addNewCar("US123BB", "Regular", "12AB", "Porsche");
    carController.addNewCar("JP123CC", "Sports", "34CD", "BMW");
    carController.addNewCar("DE123DD", "Luxury", "56EF", "Dacia");
    carController.addNewCar("IT123EE", "Sports", "78GH", "Volkswagen");
    carController.addNewCar("FR123FF", "Regular", "90IJ", "Porsche");
    carController.addNewCar("GB123GG", "Luxury", "23KL", "BMW");

    // Create UI
    UI ui = UI(carController, carsToWashController);

    // run tests
    runAllTests();

    // run app
    ui.runApp();

    return 0;
}
