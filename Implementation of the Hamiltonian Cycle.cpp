#include <iostream>
#include <vector>

using namespace std;

// Check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Check if the current vertex is connected to the previous vertex in the path
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Utility function to solve the Hamiltonian Cycle problem using backtracking
bool hamCycleUtil(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    // If all vertices are included in the cycle
    if (pos == graph.size()) {
        // And if there is an edge from the last included vertex to the first vertex
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as the next candidate in the Hamiltonian Cycle
    for (int v = 1; v < graph.size(); v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return false;
}

// Function to solve the Hamiltonian Cycle problem
bool hamCycle(const vector<vector<int>>& graph) {
    vector<int> path(graph.size(), -1);

    // Start with the first vertex in the path
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "Solution does not exist\n";
        return false;
    }

    // Print the found Hamiltonian Cycle
    cout << "Hamiltonian Cycle exists:\n";
    for (int i = 0; i < graph.size(); i++)
        cout << path[i] << " ";
    cout << path[0] << "\n"; // To complete the cycle

    return true;
}

int main() {
    // Define the adjacency matrix for the graph
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // Solve the Hamiltonian Cycle problem
    hamCycle(graph);

    return 0;
}
