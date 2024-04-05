#include "CarValidators.h"

void CarValidators::validateRegistrationNumber(const std::string &registrationNumber) {
    // check if the string is empty
    if (registrationNumber.empty()) {
        throw std::exception();
    }

    // check if it is made of 7 characters
    if (registrationNumber.size() != 7) {
        throw std::exception();
    }
}

void CarValidators::validateModel(const std::string &model) {
    // check if the string is empty
    if (model.empty()) {
        throw std::exception();
    }
}

void CarValidators::validateType(const std::string &type) {
    // check if the string is empty
    if (type.empty()) {
        throw std::exception();
    }
}

void CarValidators::validateProducer(const std::string &producer) {
    // check if the string is empty
    if (producer.empty()) {
        throw std::exception();
    }
}