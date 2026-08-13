#include <iostream>
#include <vector>
#include <utility>

// Function to maintain the min-heap property for a subtree
// n is the size of the heap, and i is the root index of the subtree
void minHeapify(std::vector<int>& arr, int n, int i) {
    int smallest = i;          // Initialize smallest as root
    int left = 2 * i + 1;      // Left child formula
    int right = 2 * i + 2;     // Right child formula

    // Check if left child exists and is smaller than the current smallest
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // Check if right child exists and is smaller than the current smallest
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If the smallest element is not the root, swap and continue heapifying
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        
        // Recursively heapify the affected subtree
        minHeapify(arr, n, smallest);
    }
}

// Main function to perform Heap Sort using Min-Heap
void minHeapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build the min-heap (rearrange the array)
    // Start from the last non-leaf node and move upwards
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (smallest element) to the end of the active heap
        std::swap(arr[0], arr[i]);

        // Call minHeapify on the reduced heap to restore order
        minHeapify(arr, i, 0);
    }
}

// Helper function to print the array contents
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

    minHeapSort(data);

    std::cout << "Sorted array (Descending order): ";
    printArray(data);

    return 0;
}
