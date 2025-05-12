#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void bellmanFord(int V, int E, vector<vector<int>>& graph, int src){
    vector<int> dist(V,INT_MAX);
    dist[src]=0;

    //Relax all edges V-1 times
    for(int i=1; i<=V-1;i++){
        for(int j=0;j<E;j++){
            int u=graph[j][0];
            int v= graph[j][1];
            int w= graph[j][2];
            if(dist[u] !=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    //PRINT DISTANCES
    for(int i=0;i<V;i++){
        if(dist[i]==INT_MAX){
            cout<<i<<": INF\n";
        }
        else{
            cout<<i<<": "<<dist[i]<<"\n";
        }
    }
}

int main(){
    int V,E;
    cout<<"Enter number of Vertices: ";
    cin>>V;
    cout<<"Enter number of Egdes";
    cin>>E;

    vector<vector<int>> graph(E, vector<int>(3));
    cout<<"Enter "<<E<<" edges in the format (u v weight): "<<endl;
    for(int i=0;i<E;i++){
        cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
    }

    int src;
    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    bellmanFord(V,E,graph,src);
    return 0;
}