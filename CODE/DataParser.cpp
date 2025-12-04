#include "DataParser.h"

// ... (Implement constructors and destructor here) ...

void DataParser::loadData(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    // Skip the header row in the CSV file
    if (std::getline(file, line)) {
        std::cout << "Loading blood units from " << filename << "..." << std::endl;
    }

    // Read the rest of the lines
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> segments;

        // Split the line by commas (',')
        while (std::getline(ss, segment, ',')) {
            segments.push_back(segment);
        }

        // Check if a full record (6 segments) was read
        if (segments.size() == 6) {
            // Create a new BloodUnit object
            BloodUnit newUnit(
                segments[0], // UnitID
                segments[1], // BloodType
                std::stoi(segments[2]), // Volume (converted to int)
                segments[3], // CollectionDate
                segments[4], // ExpirationDate
                segments[5]  // CenterID
            );

            // Create a new Node and insert it at the head of the list
            Node* newNode = new Node(newUnit);
            newNode->next = head;
            head = newNode;
        }
    }
    file.close();
    std::cout << "Successfully loaded and parsed data into Linked List." << std::endl;
}