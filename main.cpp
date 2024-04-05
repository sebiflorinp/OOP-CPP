#include <iostream>
#include "test/tests.h"
#include "controller/CarController.h"
#include "ui/UI.h"

int main() {
    // Create repository
    CarRepository carRepository = CarRepository();

    // Create Controller
    CarController carController = CarController(carRepository);

    // Create UI
    UI ui = UI(carController);

    // run tests
    runAllTests();

    // run app
    ui.runApp();
    return 0;
}
