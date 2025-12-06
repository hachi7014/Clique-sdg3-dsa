#include "DataParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept> 

// ------------------------------------------------------------------
// FIX 1: Implement the Constructor
// Purpose: Initialize the Linked List head to ensure it starts empty.
// ------------------------------------------------------------------
DataParser::DataParser() {
    head = nullptr;
}

// ------------------------------------------------------------------
// FIX 2: Implement the Destructor
// Purpose: Prevent memory leaks by deleting all nodes in the list.
// ------------------------------------------------------------------
DataParser::~DataParser() {
    Node* current = head;
    Node* next;
    
    while (current != nullptr) {
        next = current->next; // Store the next node before deleting
        delete current;      // Delete the current node
        current = next;      // Move to the next node
    }
    head = nullptr; // Ensure head is null after cleanup
    // std::cout << "DataParser: Linked List successfully destroyed." << std::endl; // Optional debug message
}

// ------------------------------------------------------------------
// 3. Implementation of the loadData function (FR1 - Prelim DSA)
// ------------------------------------------------------------------
void DataParser::loadData(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    // Skip the header row
    if (std::getline(file, line)) {
        std::cout << "Loading blood units from " << filename << "..." << std::endl;
    } else {
        std::cerr << "Error: Could not open or read header from " << filename << std::endl;
        return;
    }

    // Read the rest of the lines and insert into the Linked List
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> segments;

        // Split the line by commas (',')
        while (std::getline(ss, segment, ',')) {
            segments.push_back(segment);
        }

        // Check for complete records (6 segments)
        if (segments.size() == 6) {
            try {
                // Create a new BloodUnit object
                BloodUnit newUnit(
                    segments[0],              // UnitID
                    segments[1],              // BloodType
                    std::stoi(segments[2]),   // Volume (converted to int)
                    segments[3],              // CollectionDate
                    segments[4],              // ExpirationDate
                    segments[5]               // CenterID
                );

                // Create a new Node and insert it at the head of the list (O(1) insertion)
                Node* newNode = new Node(newUnit);
                newNode->next = head;
                head = newNode;
                
            } catch (const std::exception& e) {
                // NFR2: Robustness - Handles potential stoi errors
                std::cerr << "Data integrity error detected: " << e.what() << " on line: " << line << std::endl;
            }
        }
    }
    file.close();
    std::cout << "Successfully loaded and parsed data into Linked List." << std::endl;
}

// ------------------------------------------------------------------
// 4. Implementation of the getParsedData function
// Purpose: Converts the Linked List data into a vector for the Min Heap.
// ------------------------------------------------------------------
std::vector<BloodUnit> DataParser::getParsedData() const {
    std::vector<BloodUnit> units;
    Node* current = head;
    
    // Iterate through the Linked List and copy data to a vector
    while (current != nullptr) {
        units.push_back(current->data);
        current = current->next;
    }
    return units;
}
