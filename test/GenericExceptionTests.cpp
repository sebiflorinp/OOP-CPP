#include <cassert>
#include "GenericExceptionTests.h"
#include "../misc/Exceptions.h"

void GenericExceptionTests::testGetErrorMessage() {
    // Act
    try {
        throw GenericException("Eroare");
    } catch (GenericException& error) {
        // Assert
        assert(error.getErrorMessage() == "Eroare");
    }
}
