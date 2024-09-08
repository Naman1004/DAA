#include <iostream>
#include <vector>
using namespace std;

// Function to print the board
void printSolution(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N Queen problem
bool solveNQUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed
    if (col >= N)
        return true;

    // Try placing the queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1, N))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then backtrack
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// This function solves the N Queen problem using backtracking
bool solveNQ(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board, N);
    return true;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQ(N);

    return 0;
}
