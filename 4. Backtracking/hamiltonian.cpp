#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

bool isSafe(int v, const vector<vector<int>>& graph, vector<int>& path, int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex.
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included in the path.
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }
    return true;
}

bool hamiltonianUtil(const vector<vector<int>>& graph, vector<int>& path, int pos, int V) {
    // If all vertices are included in the path, return true
    if (pos == V)
        return true;

    // Try different vertices as the next candidate in the Hamiltonian Path.
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamiltonianUtil(graph, path, pos + 1, V))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }
    return false;
}

bool hamiltonianPath(const vector<vector<int>>& graph, int V) {
    vector<int> path(V, -1);

    // Start with the first vertex in the path
    path[0] = 0;

    if (!hamiltonianUtil(graph, path, 1, V)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // If a Hamiltonian Path exists, print the path
    cout << "Hamiltonian Path exists: ";
    for (int i = 0; i < V; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return true;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the edges (u v) for the graph:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming an undirected graph
    }

    // Function to check if a Hamiltonian Path exists
    hamiltonianPath(graph, V);

    return 0;
}
