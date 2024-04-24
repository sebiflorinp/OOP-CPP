#ifndef CPPLAB_CARCONTROLLER_H
#define CPPLAB_CARCONTROLLER_H

#include <vector>
#include "../domain/Car.h"
#include "../repository/CarRepository.h"

class CarController {
    private:
        CarRepository carRepository;
    public:
        /*
         * The constructor of the CarController class.
         * Preconditions: carRepository: an instance of the CarRepository class
         * Post-conditions: -
         */
        explicit CarController(const CarRepository& carRepository);

        /*
         * Returns the car with the received registrationNumber.
         * Preconditions: registrationNumber: a string
         * Post-conditions: an instance of the Car class
         * Raises: There is no car with the received registrationNumber
         */
        Car findCarByRegistrationNumber(const std::string& registrationNumber);

        /*
         * Returns a vector with all the cars in the repository.
         * Preconditions: -
         * Post-conditions: a vector with instances of the Car class
         */
        const std::vector<Car>& getAllCars();

        /*
         * Adds a new Car in the repository.
         * Preconditions: registrationNumber: a non-empty string
         *                type: a non-empty string
         *                model: a non-empty string
         *                producer: a non-empty string
         * Post-conditions: -
         * Raises: There is already a car with the registrationNumber of the received car
         */
        void addNewCar(const std::string& registrationNumber, const std::string& type, const std::string& model, const std::string& producer);

        /*
         * Updates the car with the received registrationNumber to match the received car
         * Preconditions: registrationNumber: a string
         *                newCar: an instance of the Car class
         * Post-conditions: -
         * Raises: There is no car with the received registrationNumber.
         *         The operation will lead to multiple cars having the same registrationNumber
         */
        void updateCarByRegistrationNumber(const std::string& registrationNumber, const std::string& newRegistrationNumber, const std::string& type, const std::string& model, const std::string& producer);

        /*
         * Deletes the car with the received registrationNumber.
         * Preconditions: registrationNumber: a string
         * Post-conditions: -
         * Raises: There is no car with the received registrationNumber
         */
        void deleteCarByRegistrationNumber(const std::string& registrationNumber);

        /*
         * Filters the instances of the Car class depending on the received string and function
         * Preconditions: toEqual: a string
         *                a function that takes a Car and a  string and return a bool
         * Post-conditions: a vector with instance of the car object
         */
        std::vector<Car> filter(std::string toEqual, std::vector<Car> (*filterByCriteria)(const std::vector<Car>&, const std::string&));

        /*
         * Sorts the instance of the Car class depending on the received string and function.
         * Preconditions: cars: an instance of the DynamicArray<Car> class.
         *                sortingOrder: a string that must be either "ASC" or "DESC"
         *                sortByCriteria: a function that takes as arguments an instance of the DynamicArray<Car> class and a string.
         */
        std::vector<Car> sort(const std::vector<Car>& cars, const std::string& sortingOrder, std::vector<Car> (*sortByCriteria)(std::vector<Car>,const std::string&));
};

#endif //CPPLAB_CARCONTROLLER_H
