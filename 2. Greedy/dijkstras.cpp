#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

void dijkstras(const vector<vector<int>>& graph, int src, int V){
    vector<int> dist(V,INT_MAX); //stored shortes dist from source
    dist[src]=0;

    //Min heap: priority queue: (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,src});

    while(!pq.empty()){
        pair<int, int> current = pq.top();
        int d = current.first;
        int u = current.second;
        pq.pop();

        if(d>dist[u]) continue;

        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
                pq.push({dist[v],v});
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    dijkstras(graph, src, V);

    return 0;
}