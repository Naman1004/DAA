#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 5  // Number of vertices in the graph

// Function to find the minimum weight Hamiltonian Cycle
int tsp(int graph[V][V], int start) {
    vector<bool> visited(V, false);
    visited[start] = true;

    int total_cost = 0;
    int current_city = start;

    for (int i = 0; i < V - 1; ++i) {
        int nearest_city = -1;
        int min_distance = INT_MAX;

        // Find the nearest unvisited city
        for (int city = 0; city < V; ++city) {
            if (!visited[city] && graph[current_city][city] < min_distance) {
                min_distance = graph[current_city][city];
                nearest_city = city;
            }
        }

        // Visit the nearest city
        visited[nearest_city] = true;
        total_cost += min_distance;
        current_city = nearest_city;
    }

    // Return to the starting point
    total_cost += graph[current_city][start];

    return total_cost;
}

int main() {
    // Graph representing distances between cities
    int graph[V][V] = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 40},
        {20, 25, 30, 0, 10},
        {25, 30, 40, 10, 0}
    };

    int start_city = 0;
    int result = tsp(graph, start_city);

    cout << "Minimum cost of the tour: " << result << endl;

    return 0;
}
