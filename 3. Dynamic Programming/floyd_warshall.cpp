//All pair shortest path
//TIME COMPLEXITY= O(n^3)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void floydWarshall(vector<vector<int>>& graph){
    int V= graph.size();
    vector<vector<int>> dist= graph;

    //Main Floyd-Warshall Algorithm
    for(int k=0;k<V; k++){ //k= intermediate vertex
        for(int i=0;i<V;i++){ //i= source vertex
            for(int j=0;j<V;j++){ //j=destination vertex
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]= dist[i][k]+dist[k][j];
                }
            }
        }
    }

    //Print Final Matrix
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j] == INT_MAX){
                cout<<"INF";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int V;
    cout<<"Enter number of vertices: ";
    cin>>V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout<<"Enter adjacency matrix (Enter 99999 for infinity)"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            int weight;
            cin>>weight;
            if(weight==99999){
                graph[i][j]=INT_MAX;
            }
            else{
                graph[i][j]=weight;
            }
        }
    }

    floydWarshall(graph);
    return 0;
}