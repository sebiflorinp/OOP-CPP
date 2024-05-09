#include "test/tests.h"
#include "ui/UI.h"
#include "repository/ProbabilityRepo.h"

int main() {

    // Create repository
    CarRepository carRepository;

    // Create Controller
    CarController carController(carRepository);
    CarsToWashController carsToWashController(carRepository);

    // Create UI
    UI ui(carController, carsToWashController);

    // run tests
    runAllTests();

    // run app
    ui.runApp();

    return 0;
}
