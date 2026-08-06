#include <iostream>
#include <vector>
#include <algorithm>

// Function to maintain the max-heap property for a subtree rooted at index 'i'
void maxHeapify(std::vector<int>& arr, int heapSize, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child formula: 2*i + 1
    int right = 2 * i + 2;    // Right child formula: 2*i + 2

    // Check if left child is larger than the root
    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than the current largest
    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root, swap and continue heapifying the affected subtree
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, heapSize, largest);
    }
}

// Main function to perform Heap Sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build a Max-Heap from the input array
    // We start from the last non-leaf node (n / 2 - 1) and go up to the root
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (the maximum element) to the end of the array
        std::swap(arr[0], arr[i]);

        // Call maxHeapify on the reduced heap (excluding the already sorted elements)
        maxHeapify(arr, i, 0);
    }
}

// Helper function to print the vector elements
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6, 7};
    
    std::cout << "Original array: ";
    printArray(data);

    heapSort(data);

    std::cout << "Sorted array (Ascending): ";
    printArray(data);

    return 0;
}
