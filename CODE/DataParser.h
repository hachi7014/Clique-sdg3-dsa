#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <string>
#include <vector>
#include "BloodUnit.h" // Needed to store BloodUnit objects

// --- 1. Define the Linked List Node Structure ---
// This is the structure that holds the data (BloodUnit) and the pointer to the next item.
struct Node {
    BloodUnit data;
    Node* next;

    Node(const BloodUnit& unit) : data(unit), next(nullptr) {}
};

// --- 2. Define the DataParser Class ---
class DataParser {
private:
    Node* head; // Head pointer for the Singly Linked List

public:
    // ------------------------------------------------------------------
    // CRITICAL: DECLARATIONS for the functions that were missing definitions!
    // ------------------------------------------------------------------
    DataParser();  // Constructor (Initializes head = nullptr)
    ~DataParser(); // Destructor (Deletes all nodes to prevent memory leaks)

    // Core functionality (FR1)
    void loadData(const std::string& filename);

    // Required for Integration: Converts Linked List data into a vector
    std::vector<BloodUnit> getParsedData() const;
};

#endif // DATAPARSER_H
