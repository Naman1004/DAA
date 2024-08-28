#include <iostream>
#include <vector>
using namespace std;

// Function to solve the knapsack problem using dynamic programming
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // The last cell of the table will have the maximum value
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    cout << "The maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
