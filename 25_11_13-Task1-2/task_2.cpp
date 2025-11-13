#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }
    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }

    bool hasParent(int index) { return getParentIndex(index) >= 0; }
    bool hasLeftChild(int index) { return getLeftChildIndex(index) < heap.size(); }
    bool hasRightChild(int index) { return getRightChildIndex(index) < heap.size(); }

    void heapifyUp() {
        int index = heap.size() - 1;
        
        while (hasParent(index) && heap[index] > heap[getParentIndex(index)]) {
            std::swap(heap[index], heap[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }

    void heapifyDown() {
        int index = 0;
        
        while (hasLeftChild(index)) {
            int largerChildIndex = getLeftChildIndex(index);
            
            if (hasRightChild(index) && heap[getRightChildIndex(index)] > heap[largerChildIndex]) {
                largerChildIndex = getRightChildIndex(index);
            }

            if (heap[index] > heap[largerChildIndex]) {
                break;
            } else {
                std::swap(heap[index], heap[largerChildIndex]);
            }
            index = largerChildIndex;
        }
    }

public:
    MaxHeap() {
    }

    // --- 2. Insertion of elements in a heap ---
    void insert(int value) {
        heap.push_back(value); // 1. Add to the end of the array
        heapifyUp();           // 2. Bubble up to correct position
        std::cout << "Inserted: " << value << std::endl;
    }

    int extractMax() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty!");
        }

        // 1. Get the root value (the max) to return later
        int maxValue = heap[0];
        
        // 2. Move the *last* element to the root
        heap[0] = heap.back();
        heap.pop_back();
        
        // 3. Bubble down from the root to fix the heap
        heapifyDown();
        
        return maxValue;
    }

    int peek() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty!");
        }
        return heap[0];
    }
    
    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    // --- 1. Creation of Max-Heap ---
    MaxHeap myHeap;
    std::cout << "--- Creating and Inserting into Max-Heap ---" << std::endl;

    // --- 2. Insertion ---
    myHeap.insert(10);
    myHeap.insert(4);
    myHeap.insert(15);
    myHeap.insert(20);
    myHeap.insert(2);
    myHeap.insert(50);

    std::cout << "\nLargest item (peek): " << myHeap.peek() << std::endl;

    // --- 3. Deletion ---
    std::cout << "\n--- Deleting (Extracting) from Max-Heap ---" << std::endl;
    while (!myHeap.isEmpty()) {
        std::cout << "Extracted: " << myHeap.extractMax() << std::endl;
    }

    return 0;
}
