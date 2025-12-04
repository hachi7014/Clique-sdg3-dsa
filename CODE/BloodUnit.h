#ifndef BLOODUNIT_H
#define BLOODUNIT_H

#include <string>

// The BloodUnit class represents one blood bag record from your data.csv
class BloodUnit {
public:
    // ------------------------------------------------------------------
    // 1. Data Members (Variables that hold the information)
    // These match the columns in your data.csv file.
    // ------------------------------------------------------------------
    std::string UnitID;        // Unique ID (e.g., BU001)
    std::string BloodType;     // (e.g., O+, A-)
    int Volume_mL;             // (e.g., 450)
    std::string CollectionDate;
    std::string ExpirationDate; // <-- CRITICAL for Min Heap Priority!
    std::string CenterID;      // (e.g., C1)

    // ------------------------------------------------------------------
    // 2. Constructor (A special function to create a BloodUnit object)
    // ------------------------------------------------------------------
    // Default Constructor (Used when you create an empty unit)
    BloodUnit();

    // Parameterized Constructor (Used when you load data from the file)
    BloodUnit(
        std::string id,
        std::string type,
        int volume,
        std::string collection,
        std::string expiration,
        std::string center
    );
};

#endif // BLOODUNIT_H