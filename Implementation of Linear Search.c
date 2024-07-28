#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i; // Return the index of the key if found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    
    int result = linearSearch(arr, size, key);
    
    if(result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    
    return 0;
}
