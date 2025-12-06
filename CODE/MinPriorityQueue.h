#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <vector>
#include <string>
#include <iostream>
#include "BloodUnit.h" // Needed to store BloodUnit objects

class MinPriorityQueue {
private:
    // The heap is implemented using a vector (array implementation)
    std::vector<BloodUnit> heap;

    // --- Core Heap Helper Functions ---

    // Function to check if Date A is EARLIER than Date B (High Priority)
    bool isEarlier(const std::string& dateA, const std::string& dateB) const;

    // Maintains the Min Heap property after insertion
    void heapifyUp(int index);

    // Maintains the Min Heap property after extraction
    void heapifyDown(int index);

    // Helper functions for array indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

public:
    // Constructor
    MinPriorityQueue() {}

    // Public API Methods (The core O(log n) operations)
    void insert(const BloodUnit& unit);
    BloodUnit extractMin();
    bool isEmpty() const { return heap.empty(); }
    int getSize() const { return heap.size(); }
};

#endif // MINPRIORITYQUEUE_H