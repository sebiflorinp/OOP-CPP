#include <string>
#include <cassert>
#include "TypeDTOTests.h"
#include "../domain/TypeDTO.h"

void TypeDTOTests::testTypeDTO() {
    // Arrange
    int count = 5;
    std::string type = "Sports";
    TypeDTO typeDTO = TypeDTO(type, count);

    // Act
    std::string actual1 = typeDTO.getType();
    int actual2 = typeDTO.getCount();

    // Assert
    assert(actual1 == type);
    assert(actual2 == count);
}
