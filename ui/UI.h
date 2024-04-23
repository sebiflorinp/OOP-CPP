#ifndef CPPLAB_UI_H
#define CPPLAB_UI_H

#include "../controller/CarController.h"
#include "vector"

class UI {
    private:
        CarController carController;

    public:
        /*
         * Displays all the cars present in the received list.
         * Preconditions:
         */
        static void displayCars(const DynamicArray<Car>& cars);
        /*
         * The constructor of the UI class
         * Preconditions: carController: an instance of the CarController class.
         * Postconditions: -
         */
        UI(const CarController& carController);

        /*
         * The function that starts the application
         * Preconditions: -
         * Postconditions: -
         */
        void runApp();

};

#endif //CPPLAB_UI_H
