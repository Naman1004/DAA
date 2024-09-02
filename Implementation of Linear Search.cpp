#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int target) {
    // Traverse the array from start to end
    for (int i = 0; i < arr.size(); ++i) {
        // Check if the current element is equal to the target
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target = 8;

    int result = linearSearch(arr, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}
