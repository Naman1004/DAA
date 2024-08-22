#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;

    // Constructor
    Item(int w, int v) : weight(w), value(v) {}
};

// Comparison function to sort items by their value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

// Function to get the maximum value in the knapsack using the greedy approach
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (auto item : items) {
        if (currentWeight + item.weight <= W) {
            // If the item can be added in its entirety
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // If the item cannot be added in its entirety, add the fraction
            int remainingWeight = W - currentWeight;
            totalValue += item.value * ((double)remainingWeight / item.weight);
            break; // As the knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Knapsack capacity
    vector<Item> items = { {10, 60}, {20, 100}, {30, 120} };

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
