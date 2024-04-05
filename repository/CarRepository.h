#ifndef CPPLAB_CARREPOSITORY_H
#define CPPLAB_CARREPOSITORY_H

#include <vector>
#include "../domain/Car.h"

class CarRepository {
    private:
        std::vector<Car> cars;

    public:
        /*
         * Returns an instace of the Car class with the received registrationNumber.
         * Preconditions: registrationNumber: a non-empty string made of 7 characters
         * Post-conditions: an instance of the Car class
         * Raises: No car with the received registrationNumber exists.
         */
        Car getCarByRegistrationNumber(const std::string& registrationNumber);

        /*
         * Returns a vector with all Car instances.
         * Preconditions: -
         * Post-conditions: a vector with instances of the Car class
         */
        const std::vector<Car>& getAllCars();

        /*
         * Adds the received Car instance in the repository.
         * Preconditions: newCar: an instance of the Car class.
         * Post-conditions: -
         * Raises: There is already another car with the same registrationNumber
         */
        void addNewCar(Car newCar);

        /*
         * Deletes the instance of the Car class with the received registrationNumber
         * Preconditions: registrationNumber: a string made of 7 characters
         * Post-conditions: -
         * Raises: No car with the received registrationNumber exists.
         */
        void deleteCarByRegistrationNumber(const std::string& registrationNumber);

        /*
         * Updates the instance of the Car class with the received registrationNumber to match updatedCar.
         * Preconditions: registrationNumber: a string made of 7 characters
         *                updatedCar: an instance of the Car class.
         * Post-conditions: -
         * Raises: No car with the received registrationNumber exists.
         */
        void updateCarByRegistrationNumber(const std::string& registrationNumber, Car updatedCar);
};

#endif //CPPLAB_CARREPOSITORY_H
