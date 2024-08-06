#include <iostream>
using namespace std;

// Function to find the maximum and minimum elements in an array
void findMaxMin(int arr[], int size, int &max, int &min) {
    max = arr[0];
    min = arr[0];
    
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max, min;
    
    findMaxMin(arr, size, max, min);
    
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
    
    return 0;
}
