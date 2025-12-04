#include "BloodUnit.h"

// We must include the header file to connect the blueprint to the instructions.

// Default Constructor Instructions
// This sets the member variables to default, safe values when the unit is created empty.
BloodUnit::BloodUnit() :
    UnitID("N/A"),
    BloodType("Unknown"),
    Volume_mL(0),
    CollectionDate("1900-01-01"),
    ExpirationDate("1900-01-01"),
    CenterID("0")
{
    // The body of the constructor is often left empty.
}

// Parameterized Constructor Instructions
// This is the function that loads the data you read from the file.
BloodUnit::BloodUnit(
    std::string id,
    std::string type,
    int volume,
    std::string collection,
    std::string expiration,
    std::string center
) :
    // We use the input parameters (id, type, etc.) to set the object's variables.
    UnitID(id),
    BloodType(type),
    Volume_mL(volume),
    CollectionDate(collection),
    ExpirationDate(expiration),
    CenterID(center)
{
    // The body is empty because the initialization is done above.
}