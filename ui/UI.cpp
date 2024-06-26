#include <iostream>
#include <utility>
#include <unordered_map>
#include "UI.h"
#include "../misc/Filters.h"
#include "../misc/SortingFunctions.h"
#include "../misc/Exceptions.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

UI::UI(CarController&  carController, CarsToWashController&  carsToWashController) : carController(carController),
                                                                                               carsToWashController(carsToWashController) {}



void UI::runApp() {
    carController.loadData();
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
                "  11. Create and display type report.\n"
                "  12. Access the menu for managing the cars that will be washed.\n"
                "  13. Undo the previous action.\n"
                "  14. Exit the application.\n";
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
        std::unordered_map<string, TypeDTO> typeReport;

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

                // try to push_back the car
                try {
                    this->carController.addNewCar(registrationNumber, type, model, producer);
                    cout << "The car was added successfully" << endl;
                    // Save the data
                    carController.saveData();
                } catch (InvalidDataError& error) {
                    cout << error.getErrorMessage();
                } catch (DuplicateDataError& error) {
                    cout << error.getErrorMessage() << endl;
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
                    // Save the data
                    carController.saveData();
                } catch (CarNotFoundError& error) {
                    cout << error.getErrorMessage() << endl;
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
                    // Save the data
                    carController.saveData();
                } catch (InvalidDataError& error) {
                    cout << error.getErrorMessage();
                } catch (DuplicateDataError& error) {
                    cout << error.getErrorMessage() << endl;
                }
                break;
            case 4:
                if (carController.getAllCars().empty()) {
                    cout << "There are no cars to display" << endl;
                } else {
                    UI::displayCars(carController.getAllCars());
                }
                break;
            case 5:
                if (this->carController.getAllCars().empty()) {
                    cout << "There are no cars." << endl;
                    break;
                }
                cout << "Input the registration number of the car you are looking for." << endl;
                cin >> registrationNumber;
                try {
                    Car foundCar = this->carController.findCarByRegistrationNumber(registrationNumber);
                    std::vector<Car> displayCar;
                    displayCar.push_back(foundCar);
                    UI::displayCars(displayCar);
                } catch (CarNotFoundError& error) {
                    cout << error.getErrorMessage() << endl;
                }
                break;
            case 6:
                if (this->carController.getAllCars().empty()) {
                    cout << "There are no cars to filter." << endl;
                    break;
                }

                cout << "Input the producer of the car." << endl;
                cin >> producer;

                {
                    std::vector<Car> filteredCars = carController.filter(producer, filterByProducer);
                    if (filteredCars.empty()) {
                        cout << "There are no cars with the input producer." << endl;
                    } else {
                        displayCars(filteredCars);
                    }
                }
                break;
            case 7:
                if (this->carController.getAllCars().empty()) {
                    cout << "There are no cars to filter." << endl;
                    break;
                }

                cout << "Input the type of the car." << endl;
                cin >> type;

                {
                    std::vector<Car> filteredCars = carController.filter(type, filterByType);
                    if (filteredCars.empty()) {
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
                if (this->carController.getAllCars().empty()) {
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
                if (this->carController.getAllCars().empty()) {
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
                // Check if there are any cars
                if (carController.getAllCars().empty()) {
                    cout << "There are no cars." << endl;
                    break;
                }

                // Create the report and display it
                typeReport = carController.createTypeReport();
                displayTypeReport(typeReport);
                break;
            case 12:
                carsToWashMenu();
                break;
            case 13:
                try {
                    carController.undo();
                    cout << "The previous action was undone successfully." << endl;
                    // Save the data
                    carController.saveData();
                } catch (UndoError& e) {
                    cout << e.getErrorMessage() << endl;
                }
                break;
            case 14:
                running = false;
                cout << "Thank you for using this application." << endl;
                break;
            default:
                cout << "The input option is not valid." << endl;
                break;
        }

    }
}

void UI::displayCars(const std::vector<Car>& cars) {
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

void UI::carsToWashMenu() {
    cout << "This is the menu for managing the cars that will be washed." << endl;
    cout << "In order to use it you have to choose one of the following options:\n";
    cout << "  1. Add a car in the list by the registration number.\n"
            "  2. Empty the list.\n"
            "  3. Add random cars until the list has a certain number of cars.\n"
            "  4. Export the list as a CSV or HTML.\n"
            "  5. Exit the menu.\n";
    int option;
    while (true) {
        cout << "Choose an option." << endl;
        try {
            cin >> option;
            if (option < 1 || option > 5) {
                throw std::exception();
            }
        } catch (...) {
            cout << "The input option is not valid, please input a valid action." << std::endl;
            continue;
        }
        string registrationNumber;
        int totalNumberOfCars;
        string exportFormat;
        string fileName;

        switch (option) {
            case 1:
                displayCars(carController.getAllCars());
                cout << "Input the registration number of the car." << endl;
                cin >> registrationNumber;
                try {
                    carsToWashController.addCarToWashRepository(registrationNumber);
                    cout << "The car was added to the list successfully." << endl;
                } catch (CarNotFoundError& error) {
                    cout << error.getErrorMessage() << endl;
                } catch (DuplicateDataError& error) {
                    cout << error.getErrorMessage() << endl;
                }
                break;
            case 2:
                carsToWashController.emptyRepository();
                cout << "The list was emptied successfully." << endl;
                break;
            case 3:
                cout << "Input the total number of cars that will be in the list." << endl;
                try {
                    cin >> totalNumberOfCars;
                } catch (...) {
                    cout << "The input is not an integer." << endl;
                    break;
                }

                if (totalNumberOfCars < carsToWashController.GetAllCars().size()) {
                    cout << "The list already has more cars than the input number." << endl;
                    break;
                }

                if (totalNumberOfCars > carController.getAllCars().size()) {
                    cout << "There are not enough cars to add in the list." << endl;
                    break;
                }

                carsToWashController.addRandomCars(totalNumberOfCars);
                cout << "The cars were added successfully." << endl;
                break;
            case 4:
                // Get the export format
                cout << "Choose the export format between CSV and HTML." << endl;
                cin >> exportFormat;
                if (exportFormat != "CSV" && exportFormat != "HTML") {
                    cout << "Invalid export format." << endl;
                    break;
                }

                // Get the name of the file
                cout << "Input the name of the file that will be created." << endl;
                cin >> fileName;

                // Export the cars
                try {
                    carsToWashController.exportCarsToWash(exportFormat, fileName);
                    cout << "The cars were exported successfully." << endl;
                } catch (InvalidExportFormatError& error) {
                    cout << error.getErrorMessage() << endl;
                }
                break;
            case 5:
                return;
                break;
        }
    }


}

void UI::displayTypeReport(const std::unordered_map<std::string, TypeDTO> &typeReport) {
    printf("+------------------------+-------------------+\n");
    printf("|  %-20s  |  %-15s  |\n", "Type", "Count");
    printf("+------------------------+-------------------+\n");

    for (auto& pair: typeReport) {
        printf("|  %-20s  |  %-15d  |\n", pair.first.c_str(), pair.second.getCount());
        printf("+------------------------+-------------------+\n");
    }
    if (typeReport.empty()) {
        printf("|  %-20s  |  %-15s  |\n", " ", " ");
        printf("+------------------------+-------------------+\n");
    }
}
