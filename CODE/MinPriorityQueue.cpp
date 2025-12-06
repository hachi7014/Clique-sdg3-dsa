#include "MinPriorityQueue.h"
#include <algorithm> // for std::swap
#include <stdexcept> // for runtime_error

// ------------------------------------------------------------------
// CRITICAL LOGIC: Determines Priority based on ExpirationDate
// This ensures the unit closest to expiration is always prioritized.
// ------------------------------------------------------------------
bool MinPriorityQueue::isEarlier(const std::string& dateA, const std::string& dateB) const {
    // String comparison works because the date format is YYYY-MM-DD.
    // dateA < dateB means dateA is chronologically earlier and thus higher priority.
    return dateA < dateB;
}

// ------------------------------------------------------------------
// Core O(log n) Insertion Logic
// ------------------------------------------------------------------
void MinPriorityQueue::insert(const BloodUnit& unit) {
    // 1. Add the new element to the end of the vector. (O(1))
    heap.push_back(unit);

    // 2. Restore the Min Heap property by bubbling up the new element. (O(log n))
    heapifyUp(heap.size() - 1);
}

// ------------------------------------------------------------------
// Core O(log n) Extraction Logic (Fulfills FR3)
// ------------------------------------------------------------------
BloodUnit MinPriorityQueue::extractMin() {
    if (isEmpty()) {
        // NFR2: Robustness check
        throw std::runtime_error("Heap is empty. Cannot extract minimum.");
    }

    // 1. The highest priority item (closest to expiration) is at the root.
    BloodUnit minUnit = heap[0];

    // 2. Move the last item to the root position and remove the old last item. (O(1))
    heap[0] = heap.back();
    heap.pop_back();

    // 3. Restore the Min Heap property by bubbling down the new root. (O(log n))
    if (!isEmpty()) {
        heapifyDown(0);
    }

    return minUnit;
}


// ------------------------------------------------------------------
// Min Heap Maintenance Functions (O(log n) Time Complexity)
// ------------------------------------------------------------------
void MinPriorityQueue::heapifyUp(int index) {
    // While current node is not root AND its expiration date is earlier (higher priority) than its parent:
    while (index > 0 && isEarlier(heap[index].ExpirationDate, heap[parent(index)].ExpirationDate)) {
        // Swap the child with the parent
        std::swap(heap[index], heap[parent(index)]);
        
        // Move up to the parent's index
        index = parent(index);
    }
}

void MinPriorityQueue::heapifyDown(int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    // Check if the left child is smaller/earlier than the current node
    if (left < heap.size() && isEarlier(heap[left].ExpirationDate, heap[smallest].ExpirationDate)) {
        smallest = left;
    }

    // Check if the right child is smaller/earlier than the current smallest node
    if (right < heap.size() && isEarlier(heap[right].ExpirationDate, heap[smallest].ExpirationDate)) {
        smallest = right;
    }

    // If the smallest node is not the current node, swap and continue heapifying down
    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}
