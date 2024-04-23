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

    // Add some cars for testing purposes
    carController.addNewCar("RO123AA", "Regular", "12AA", "Dacia");
    carController.addNewCar("EN123RR", "Regular", "23AA", "Dacia");
    carController.addNewCar("DE123VV", "Sports", "66FF", "Mercedes");
    carController.addNewCar("RO444WW", "Sports", "11DD", "Dacia");

    // Create UI
    UI ui = UI(carController);

    // run tests
    runAllTests();

    // run app
    ui.runApp();

    return 0;
}
