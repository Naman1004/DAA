#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1); // Randomly select a pivot
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]); // Move pivot to end

    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Move pivot to its correct position
    return i + 1;
}

// Recursive function to implement Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1); // Sort elements before partition
        randomizedQuickSort(arr, pi + 1, high); // Sort elements after partition
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted array: ";
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
