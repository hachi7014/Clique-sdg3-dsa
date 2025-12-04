#ifndef DATAPARSER_H
#define DATAPARSER_H

#include "BloodUnit.h" // Must include the BloodUnit class to store its objects
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// 1. The Node Structure (The Link)
struct Node {
    BloodUnit data; // This node holds one BloodUnit object
    Node* next;     // Pointer to the next node in the list

    // Constructor for the Node
    Node(const BloodUnit& unit) : data(unit), next(nullptr) {}
};

// 2. The DataParser Class (The Linked List Manager)
class DataParser {
private:
    Node* head; // The start of the list
    
public:
    DataParser(); // Constructor
    ~DataParser(); // Destructor (to clean up memory)

    // Function to read the file and build the list
    void loadData(const std::string& filename); 
    
    // Function to retrieve the parsed data for the Min Heap
    std::vector<BloodUnit> getParsedData() const;
};

#endif // DATAPARSER_H