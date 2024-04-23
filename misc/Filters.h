#ifndef CPPLAB_FILTERS_H
#define CPPLAB_FILTERS_H

#include "DynamicArray.h"
#include "../domain/Car.h"

/*
 * Filters the cars by the producer.
 * Preconditions: cars: an instance of the DynamicArray class.
 *                producer: a string
 * Post-conditions: an instance of the DynamicArray class.
 */
DynamicArray<Car> filterByProducer(const DynamicArray<Car>& cars, const std::string& producer);

/*
 * Filters the cars by the type.
 * Preconditions: cars: an instance of the DynamicArray class.
 *                producer: a string
 * Post-conditions: an instance of the DynamicArray class.
 */
DynamicArray<Car> filterByType(const DynamicArray<Car>& cars, const std::string& type);

#endif //CPPLAB_FILTERS_H
