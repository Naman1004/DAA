#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

// n is the number of cities
int n;
// dp table to store minimum cost
vector<vector<int>> dp;
// adj matrix to store the distances between cities
vector<vector<int>> adj;

// Function to solve TSP using DP
int tsp(int mask, int pos) {
    // Base case: if all cities have been visited
    if (mask == (1 << n) - 1) {
        return adj[pos][0]; // return to the starting city
    }

    // Return the stored result if already computed
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    // Initialize the minimum cost to infinity
    int minCost = INF;

    // Try to visit all other cities
    for (int city = 0; city < n; city++) {
        // Check if the city is not yet visited
        if (!(mask & (1 << city))) {
            // Recursively calculate the cost of visiting this city
            int newCost = adj[pos][city] + tsp(mask | (1 << city), city);
            minCost = min(minCost, newCost); // Take the minimum cost
        }
    }

    // Store the result in dp table and return
    return dp[mask][pos] = minCost;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    // Resize the dp and adj matrices
    dp.resize(1 << n, vector<int>(n, -1));
    adj.resize(n, vector<int>(n));

    // Input the adjacency matrix (distances between cities)
    cout << "Enter the adjacency matrix (distances between cities):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // Start TSP from the first city (index 0) with an initial mask of visiting only the first city
    int result = tsp(1, 0);
    cout << "The minimum traveling cost is: " << result << endl;

    return 0;
}
