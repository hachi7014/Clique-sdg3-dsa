#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept> 
#include "BloodUnit.h" // Needed to store BloodUnit objects

class MinPriorityQueue {
private:
    // The heap is implemented using a vector (array implementation)
    std::vector<BloodUnit> heap;

    // Helper Function Prototypes
    // Used to compare dates for priority: returns true if dateA is earlier (higher priority)
    bool isEarlier(const std::string& dateA, const std::string& dateB) const;

    // Maintains the Min Heap property after insertion (O(log n))
    void heapifyUp(int index);
    
    // Maintains the Min Heap property after extraction (O(log n))
    void heapifyDown(int index);

    // Helper functions for array indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

public:
    MinPriorityQueue() {}

    // Core O(log n) Operations
    void insert(const BloodUnit& unit);
    BloodUnit extractMin();

    // ------------------------------------------------------------------
    // Final Logic: PeekMin (Defined inline in the header)
    // Used for Menu Option 3 in main.cpp.
    // ------------------------------------------------------------------
    BloodUnit peekMin() const { 
        if (isEmpty()) {
            // Robustness check (NFR2)
            throw std::runtime_error("Heap is empty. Cannot peek."); 
        }
        // The highest priority item (closest to expiration) is always at the root (index 0).
        return heap[0]; 
    }

    // Status Checkers
    bool isEmpty() const { return heap.empty(); }
    int getSize() const { return heap.size(); }
};

#endif // MINPRIORITYQUEUE_H
