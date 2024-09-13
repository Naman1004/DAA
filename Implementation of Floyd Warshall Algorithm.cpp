#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// Number of vertices in the graph
#define V 4

// A function to print the solution matrix
void printSolution(const vector<vector<int>>& dist) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX)
                cout << "INF" << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

// Function to implement Floyd Warshall Algorithm
void floydWarshall(vector<vector<int>>& graph) {
    // Create a 2D matrix to store distances
    vector<vector<int>> dist = graph;

    // Updating the solution matrix
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, update dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main() {
    // Let the INF represent no edge between two vertices
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}
    };

    // Call Floyd Warshall algorithm
    floydWarshall(graph);

    return 0;
}
