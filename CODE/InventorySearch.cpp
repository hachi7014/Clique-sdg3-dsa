#include "InventorySearch.h"
#include <iostream>

// ------------------------------------------------------------------
// O(n^2) Implementation: Selection Sort (A custom, simple sort)
// This is necessary because Binary Search requires sorted data.
// ------------------------------------------------------------------
void InventorySearch::sortInventory(std::vector<BloodUnit>& units) {
    int n = units.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            // Sort criteria: Alphabetically by UnitID
            if (units[j].UnitID < units[min_idx].UnitID) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the element at position i
        if (min_idx != i) {
            std::swap(units[min_idx], units[i]);
        }
    }
    std::cout << "Inventory sorted by UnitID for efficient searching." << std::endl;
}

// ------------------------------------------------------------------
// O(log n) Implementation: Binary Search
// ------------------------------------------------------------------
int InventorySearch::binarySearch(const std::vector<BloodUnit>& units, const std::string& targetId) const {
    int left = 0;
    int right = units.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (units[mid].UnitID == targetId) {
            return mid; // Found! Return the index
        }

        // If target is greater, ignore the left half
        if (units[mid].UnitID < targetId) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Not found
}