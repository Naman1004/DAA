#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string longestCommonSubsequence(const std::string& X, const std::string& Y) {
    int m = X.length();
    int n = Y.length();
    
    // Create a 2D array to store lengths of longest common subsequence.
    std::vector<std::vector<int>> L(m + 1, std::vector<int>(n + 1, 0));
    
    // Build the L table from bottom-up
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    // Recover the LCS from the L table
    int index = L[m][n];
    std::string lcs(index, '\0');
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            --i;
            --j;
            --index;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    
    return lcs;
}

int main() {
    std::string X = "AGGTAB"; // Example string 1
    std::string Y = "GXTXAYB"; // Example string 2
    
    std::string lcs = longestCommonSubsequence(X, Y);
    
    std::cout << "Longest Common Subsequence: " << lcs << std::endl;
    
    return 0;
}
