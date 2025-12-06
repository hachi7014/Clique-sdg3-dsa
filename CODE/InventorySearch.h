#ifndef INVENTORYSEARCH_H
#define INVENTORYSEARCH_H

#include "BloodUnit.h"
#include <vector>
#include <string>
#include <algorithm> // Needed for std::swap or std::sort

class InventorySearch {
public:
    // --- Core Methods ---
    
    // Sorts the inventory by UnitID (prepares data for O(log n) search)
    void sortInventory(std::vector<BloodUnit>& units);

    // Performs a Binary Search on the sorted vector by UnitID
    // Complexity Goal: O(log n)
    int binarySearch(const std::vector<BloodUnit>& units, const std::string& targetId) const;
};

#endif // INVENTORYSEARCH_H