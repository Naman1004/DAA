#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a connected, undirected, and weighted graph
struct Graph {
    int V, E; // V = Number of vertices, E = Number of edges
    vector<Edge> edges;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// A utility function to find the subset of an element 'i'
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function that does union of two sets of 'x' and 'y'
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else { 
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights
bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// Function to implement Kruskal's Algorithm to find the MST
void KruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result; // To store the resultant MST

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Allocate memory for creating V subsets
    Subset* subsets = new Subset[(V * sizeof(Subset))];

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is V-1
    for (Edge edge : graph.edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        // If including this edge doesn't cause a cycle
        if (x != y) {
            result.push_back(edge);
            Union(subsets, x, y);
        }

        // If we have enough edges in the MST, break
        if (result.size() == V - 1) break;
    }

    // Print the contents of result[] to display the MST
    cout << "Following are the edges in the constructed MST\n";
    for (auto& edge : result)
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;

    delete[] subsets; // Free the memory allocated for subsets
}

// Function to create a graph with V vertices and E edges
Graph createGraph(int V, int E) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edges = vector<Edge>(E);
    return graph;
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph graph = createGraph(V, E);

    // add edge 0-1
    graph.edges[0] = {0, 1, 10};
    // add edge 0-2
    graph.edges[1] = {0, 2, 6};
    // add edge 0-3
    graph.edges[2] = {0, 3, 5};
    // add edge 1-3
    graph.edges[3] = {1, 3, 15};
    // add edge 2-3
    graph.edges[4] = {2, 3, 4};

    KruskalMST(graph);

    return 0;
}
