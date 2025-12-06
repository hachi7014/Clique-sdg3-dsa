#include "MinPriorityQueue.h"
#include <algorithm> // for std::swap

// ------------------------------------------------------------------
// CRITICAL LOGIC: Determines Priority based on ExpirationDate
// If dateA is EARLIER (closer to today) than dateB, dateA has higher priority.
// Since the dates are in YYYY-MM-DD format, string comparison works directly!
// ------------------------------------------------------------------
bool MinPriorityQueue::isEarlier(const std::string& dateA, const std::string& dateB) const {
    // If dateA (e.g., 2025-12-10) is less than dateB (e.g., 2025-12-15), 
    // it means dateA is EARLIER, so dateA is the higher priority (smaller in Min Heap).
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
// Core O(log n) Extraction Logic
// ------------------------------------------------------------------
BloodUnit MinPriorityQueue::extractMin() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty. Cannot extract minimum.");
    }

    // 1. The highest priority item (closest to expiration) is at the root.
    BloodUnit minUnit = heap[0];

    // 2. Move the last item to the root position. (O(1))
    heap[0] = heap.back();

    // 3. Remove the last item (the copy). (O(1))
    heap.pop_back();

    // 4. Restore the Min Heap property by bubbling down the new root. (O(log n))
    if (!isEmpty()) {
        heapifyDown(0);
    }

    return minUnit;
}


// ------------------------------------------------------------------
// Min Heap Maintenance Functions (O(log n))
// ------------------------------------------------------------------
void MinPriorityQueue::heapifyUp(int index) {
    // While the current node is not the root AND its expiration date is earlier 
    // (higher priority) than its parent's expiration date:
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