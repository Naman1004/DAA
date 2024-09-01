#include <iostream>
#include <vector>

using namespace std;

// Function to print a subset
void printSubset(const vector<int>& subset) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

// Backtracking function to find subsets with the desired sum
void findSubsets(const vector<int>& nums, int targetSum, vector<int>& subset, int index, int currentSum) {
    // If the current sum matches the target sum, print the subset
    if (currentSum == targetSum) {
        printSubset(subset);
        return;
    }

    // If the current sum exceeds the target sum or we have considered all elements, stop
    if (currentSum > targetSum || index >= nums.size()) {
        return;
    }

    // Include the current element in the subset and proceed
    subset.push_back(nums[index]);
    findSubsets(nums, targetSum, subset, index + 1, currentSum + nums[index]);

    // Exclude the current element from the subset and proceed
    subset.pop_back();
    findSubsets(nums, targetSum, subset, index + 1, currentSum);
}

int main() {
    vector<int> nums = {10, 7, 5, 18, 12, 20, 15}; // Example set of numbers
    int targetSum = 35; // Example target sum
    vector<int> subset; // Vector to store the current subset

    cout << "Subsets of given set with sum " << targetSum << " are:" << endl;
    findSubsets(nums, targetSum, subset, 0, 0);

    return 0;
}
