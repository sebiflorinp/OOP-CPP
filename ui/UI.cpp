#include <iostream>
#include "UI.h"
#include "../misc/Filters.h"
#include "../misc/SortingFunctions.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

UI::UI(const CarController& carController) : carController(carController) {
    this->carController = carController;
}



void UI::runApp() {
    bool running = true;
    cout << "This is a car management application." << std::endl;
    cout << "In order to use it you have to choose one of the following options:\n";
    while (running) {
        int option = 6;
        cout << "  1. Add a new car. \n"
                "  2. Delete a car. \n"
                "  3. Update a car. \n"
                "  4. Display all the cars.\n"
                "  5. Find a car by registration number.\n"
                "  6. Filter cars by producer.\n"
                "  7. Filter cars by type.\n"
                "  8. Sort cars by registration number.\n"
                "  9. Sort cars by type.\n"
                "  10. Sort cars by producer and model.\n"
                "  11. Exit the application.\n";
        try {
            cin >> option;
        } catch (...) {
            cout << "The option is not an integer. Please input an integer." << std::endl;
            continue;
        }
        // variables required for adding a new car
        string newRegistrationNumber;
        string registrationNumber;
        string type;
        string model;
        string producer;
        string producerToFilterBy;


        switch (option) {
            case 1:
                // get required fields from the user
                cout << "Input the registration number of the car" << std::endl;
                cin >> registrationNumber;

                cout << "Input the type of the car" << std::endl;
                cin >> type;

                cout << "Input the model of the car" << std::endl;
                cin >> model;

                cout << "Input the producer of the car" << std::endl;
                cin >> producer;

                // try to add the car
                try {
                    this->carController.addNewCar(registrationNumber, type, model, producer);
                    cout << "The car was added successfully" << endl;
                } catch (...) {
                    cout << "The entered data is invalid or there is already a car with the input registration number" << endl;
                }
                break;
            case 2:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars to delete" << endl;
                    break;
                }
                this->displayCars(this->carController.getAllCars());
                cout << "Input the registration number of the car that will be deleted:" << endl;
                cin >> registrationNumber;
                try {
                    this->carController.deleteCarByRegistrationNumber(registrationNumber);
                    cout << "The car was deleted successfully!" << endl;
                } catch (...) {
                    cout << "There is no car with the input registration number." << endl;
                }
                break;
            case 3:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars to update." <<endl;
                    break;
                }
                UI::displayCars(this->carController.getAllCars());

                cout << "Input the registration number of the car that will be updated." << endl;
                cin >> registrationNumber;

                cout << "Input the updated registration number." << endl;
                cin >> newRegistrationNumber;

                cout << "Input the updated type." << endl;
                cin >> type;

                cout << "Input the updated model." << endl;
                cin >> model;

                cout << "Input the updated producer." << endl;
                cin >> producer;

                try {
                    this->carController.updateCarByRegistrationNumber(registrationNumber, newRegistrationNumber, type,
                            model, producer);
                    cout << "The car was updated successfully." << endl;
                } catch (...) {
                    cout << "The update could not pe performed." << endl;
                }

                break;
            case 4:
                if (carController.getAllCars().size() == 0) {
                    cout << "There are no cars to display" << endl;
                } else {
                    UI::displayCars(carController.getAllCars());
                }
                break;
            case 5:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars." << endl;
                    break;
                }
                cout << "Input the registration number of the car you are looking for." << endl;
                cin >> registrationNumber;
                try {
                    Car foundCar = this->carController.findCarByRegistrationNumber(registrationNumber);
                    DynamicArray<Car> displayCar;
                    displayCar.add(foundCar);
                    UI::displayCars(displayCar);
                } catch (...) {
                    cout << "There is no car with the input registration number" << endl;
                }
                break;
            case 6:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars to filter." << endl;
                    break;
                }

                cout << "Input the producer of the car." << endl;
                cin >> producer;

                {
                    DynamicArray<Car> filteredCars = carController.filter(producer, filterByProducer);
                    if (filteredCars.size() == 0) {
                        cout << "There are no cars with the input producer." << endl;
                    } else {
                        displayCars(filteredCars);
                    }
                }
                break;
            case 7:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars to filter." << endl;
                    break;
                }

                cout << "Input the type of the car." << endl;
                cin >> type;

                {
                    DynamicArray<Car> filteredCars = carController.filter(type, filterByType);
                    if (filteredCars.size() == 0) {
                        cout << "There are no cars with the input type." << endl;
                    } else {
                        displayCars(filteredCars);
                    }
                }
                break;
            case 8:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars to sort." << endl;
                    break;
                }
                cout << "Input sorting order: ASC / DESC." <<endl;
                {
                    string ordering;
                    cin >> ordering;
                    if (ordering != "ASC" && ordering != "DESC") {
                        cout << "Invalid sorting order." << endl;
                        break;
                    }
                    displayCars(carController.sort(carController.getAllCars(), ordering, sortCarsByRegistrationNumber));
                }
                break;
            case 9:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars to sort." << endl;
                    break;
                }
                cout << "Input sorting order: ASC / DESC." <<endl;
                {
                    string ordering;
                    cin >> ordering;
                    if (ordering != "ASC" && ordering != "DESC") {
                        cout << "Invalid sorting order." << endl;
                        break;
                    }
                    displayCars(carController.sort(carController.getAllCars(), ordering, sortCarsByType));
                }
                break;
            case 10:
                if (this->carController.getAllCars().size() == 0) {
                    cout << "There are no cars to sort." << endl;
                    break;
                }
                cout << "Input sorting order: ASC / DESC." <<endl;
                {
                    string ordering;
                    cin >> ordering;
                    if (ordering != "ASC" && ordering != "DESC") {
                        cout << "Invalid sorting order." << endl;
                        break;
                    }
                    displayCars(carController.sort(carController.getAllCars(), ordering, sortCarsByProducerAndModel));
                }
                break;
            case 11:
                running = false;
                cout << "Thank you for using this application." << endl;
                break;
            default:
                cout << "The input option is not valid." << endl;
                break;
        }

    }
}

void UI::displayCars(const DynamicArray<Car>& cars) {
    printf("+------------------------+-------------------+-------------------+-------------------+\n");
    printf("|  %-20s  |  %-15s  |  %-15s  |  %-15s  |\n", "Registration Number", "Type", "Model", "Producer");
    printf("+------------------------+-------------------+-------------------+-------------------+\n");

    for (auto& car: cars) {
        printf("|  %-20s  |  %-15s  |  %-15s  |  %-15s  |\n", car.getRegistrationNumber().c_str(), car.getType().c_str(), car.getModel().c_str(), car.getProducer().c_str());
        printf("+------------------------+-------------------+-------------------+-------------------+\n");
    }
    if (cars.size() == 0) {
        printf("|  %-20s  |  %-15s  |  %-15s  |  %-15s  |\n", " ", " ", " ", " ");
        printf("+------------------------+-------------------+-------------------+-------------------+\n");

    }
}
