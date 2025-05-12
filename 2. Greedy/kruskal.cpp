#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u,v,weight;
};

// Comparator to sort edges by weight
bool compare(Edge a, Edge b){
    return a.weight<b.weight;
}

// DSU (Disjoint Set Union) structure
vector<int> parent;

int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void unite(int x,int y){
    int rootX=find(x);
    int rootY= find(y);
    parent[rootX]=rootY;
}

int main(){
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compare);

    // Initialize parent array for DSU
    parent.resize(V + 1);
    for (int i = 1; i <= V; i++) parent[i] = i;

    int mstWeight = 0;
    vector<Edge> mst;

    // Kruskal's main loop
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // Check if u and v are in different sets (no cycle)
        if (find(u) != find(v)) {
            mst.push_back(edges[i]);  // Add this edge to the MST
            mstWeight += w;           // Add the edge's weight
            unite(u, v);              // Merge the two sets
        }
    }

    // Output MST
    cout << "\nMinimum Spanning Tree edges:\n";
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << "\n";
    }
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;

}