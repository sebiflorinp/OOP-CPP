#ifndef CPPLAB_UI_H
#define CPPLAB_UI_H

#include "../controller/CarController.h"
#include "vector"
#include "../controller/CarsToWashController.h"

class UI {
    private:
        CarController carController;
        CarsToWashController carsToWashController;

    public:
        /*
         * Displays all the cars present in the received list.
         * Preconditions:
         */
        static void displayCars(const std::vector<Car>& cars);
        /*
         * The constructor of the UI class
         * Preconditions: carController: an instance of the CarController class.
         * Postconditions: -
         */
        UI(CarController  carController, CarsToWashController  carsToWashController);

        /*
         * The function that starts the application
         * Preconditions: -
         * Postconditions: -
         */
        void runApp();

        /*
         * Starts the cars to wash menu.
         * Preconditions: -
         * Postconditions: -
         */
        void carsToWashMenu();

        /*
         * Displays the type report.
         * Preconditions: typeReport: a map having a string as the key and a TypeDTO as the value.
         * Postconditions: -
         */
        void displayTypeReport(const std::unordered_map<std::string, TypeDTO>& typeReport);
};

#endif //CPPLAB_UI_H
