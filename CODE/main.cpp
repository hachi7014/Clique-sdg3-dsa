#include <iostream>
#include <vector>
#include <stdexcept>
#include "BloodUnit.h"          // The data structure
#include "DataParser.h"         // Linked List (Prelim - FR1)
#include "MinPriorityQueue.h"   // Min Heap (Finals - FR3)
#include "InventorySearch.h"    // Binary Search (Midterm)

using namespace std;

// Function Prototypes
void displayMenu();
void runApplication();

int main() {
    // Setting up to handle console I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    runApplication();
    return 0;
}

void displayMenu() {
    cout << "\n--- Blood Donation Management System (SDG 3) ---" << endl;
    cout << "1. Dispatch Top Priority Unit (FR3: Min Heap - O(log n))" << endl;
    cout << "2. Search for Blood Unit by ID (Midterm: Binary Search - O(log n))" << endl;
    cout << "3. Check Current Priority Unit" << endl;
    cout << "0. Exit System" << endl;
    cout << "-----------------------------------------------" << endl;
}

void runApplication() {
    // 1. DATA LOADING (FR1 - Prelim Concept)
    DataParser parser;
    // Load data from the CSV file into the Linked List
    parser.loadData("INPUT_DATA/data.csv"); 

    // Retrieve the parsed data from the Linked List into a vector for further use
    vector<BloodUnit> inventory = parser.getParsedData();
    
    // 2. CORE ALGORITHM SETUP (FR3 - Finals Concept)
    MinPriorityQueue priorityQueue;
    cout << "System Status: Building Min Heap for prioritized dispatch..." << endl;
    
    // Populate the Min Heap: This creates the priority structure (O(N log N) total)
    for (const auto& unit : inventory) {
        priorityQueue.insert(unit);
    }
    cout << "System Status: Min Heap successfully loaded with " << priorityQueue.getSize() << " units." << endl;

    // --- MAIN APPLICATION LOOP (FR4) ---
    int choice;
    do {
        displayMenu();
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) { // Handle non-integer input
            cout << "\nError: Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: { // DISPATCH (FR3: Min Heap Extraction)
                try {
                    BloodUnit dispatched = priorityQueue.extractMin(); // O(log n)
                    cout << "\n[DISPATCHED] SUCCESS! Highest priority unit sent:" << endl;
                    cout << "   Unit ID: " << dispatched.UnitID 
                         << " | Type: " << dispatched.BloodType 
                         << " | Expiration Date: " << dispatched.ExpirationDate << endl;
                } catch (const runtime_error& e) {
                    cout << "\n[ERROR] Inventory is empty. Cannot dispatch." << endl;
                }
                break;
            }
            case 2: { // SEARCH (Midterm: Binary Search)
                InventorySearch searcher;
                
                // 1. Sort the vector (required for Binary Search)
                searcher.sortInventory(inventory); 

                string targetId;
                cout << "Enter the Unit ID to search (e.g., BU025): ";
                cin >> targetId;

                // 2. Perform Binary Search (O(log n))
                int index = searcher.binarySearch(inventory, targetId);
                
                if (index != -1) {
                    const BloodUnit& foundUnit = inventory[index];
                    cout << "\n[FOUND] Unit ID: " << foundUnit.UnitID 
                         << " | Type: " << foundUnit.BloodType 
                         << " | Volume: " << foundUnit.Volume_mL 
                         << "mL | EXP: " << foundUnit.ExpirationDate << endl;
                } else {
                    cout << "\n[NOT FOUND] Unit ID " << targetId << " does not exist in inventory." << endl;
                }
                break;
            }
            case 3: { // CHECK PRIORITY UNIT
                if (priorityQueue.isEmpty()) {
                    cout << "\n[STATUS] Inventory is empty." << endl;
                } else {
                    BloodUnit top = priorityQueue.peekMin(); // Assumes you added a peekMin method to MinPriorityQueue
                    cout << "\n[PRIORITY] Next unit for dispatch is: " << top.UnitID 
                         << " (Expires: " << top.ExpirationDate << ")" << endl;
                }
                break;
            }
            case 0:
                cout << "\nSystem Shutdown. Thank you for using the BDMS." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please enter 0, 1, 2, or 3." << endl;
        }
    } while (choice != 0);
}