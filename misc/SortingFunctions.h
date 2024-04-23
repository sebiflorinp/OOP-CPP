#ifndef CPPLAB_SORTINGFUNCTIONS_H
#define CPPLAB_SORTINGFUNCTIONS_H

#include "../domain/Car.h"
#include "DynamicArray.h"

/*
 * Sorts the given cars by their registration numbers.
 * Preconditions: cars: an instance of the DynamicArray class.
 *                sortingOrdering: a string that has to be either ASC or DESC
 * Post-conditions: an instance of the DynamicArray class.
 */
DynamicArray<Car> sortCarsByRegistrationNumber(DynamicArray<Car> cars,const std::string& sortingOrder);

/*
 * Sorts the given cars by their types.
 * Preconditions: cars: an instance of the DynamicArray class.
 *                sortingOrdering: a string that has to be either ASC or DESC
 * Post-conditions: an instance of the DynamicArray class.
 */
DynamicArray<Car> sortCarsByType(DynamicArray<Car> cars,const std::string& sortingOrder);

/*
 * Sorts the given cars by their producers and models.
 * Preconditions: cars: an instance of the DynamicArray class.
 *                sortingOrdering: a string that has to be either ASC or DESC
 * Post-conditions: an instance of the DynamicArray class.
 */
DynamicArray<Car> sortCarsByProducerAndModel(DynamicArray<Car> cars,const std::string& sortingOrder);

/*
 * Compares the registration numbers of two cars.
 * Preconditions: firstCar: an instance of the Car class.
 *                secondCar: an instance of the Car class.
 *                sortingOrder: a string that has to be either ASC or DESC
 * Post-conditions: an integer that is -1, 0 or 1
 */
int compareRegistrationNumbers(Car& firstCar,Car& secondCar,const std::string& sortingOrder);

/*
 * Compares the types of two cars.
 * Preconditions: firstCar: an instance of the Car class.
 *                secondCar: an instance of the Car class.
 *                sortingOrder: a string that has to be either ASC or DESC
 * Post-conditions: an integer that is -1, 0 or 1
 */
int compareTypes(Car& firstCar, Car& secondCar, const std::string& sortingOrder);

/*
 * Compares the producers and models of two cars.
 * Preconditions: firstCar: an instance of the Car class.
 *                secondCar: an instance of the Car class.
 *                sortingOrder: a string that has to be either ASC or DESC
 * Post-conditions: an integer that is -1, 0 or 1
 */
int compareProducersAndModels(Car& firstCar,Car& secondCar,const std::string& sortingOrder);

#endif //CPPLAB_SORTINGFUNCTIONS_H
