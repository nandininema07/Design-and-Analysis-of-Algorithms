#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    int n; //number of vertices
    int cost[100][100];

    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter cost adjacency matrix (use 0 if no edge)";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            if(cost[i][j]==0){
                cost[i][j]=INT_MAX; // Replace 0 with INF for no edge
            }
        }
    }

    int selected[100]={0}; // Tracks whether a vertex is included in MST
    selected[0]=1;
    int edgeCount=0;
    int minCost=0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";

    while(edgeCount<n-1){
        int u=-1, v=-1;
        int min=INT_MAX;

        // Find the minimum cost edge from selected to unselected vertex
        for(int i=0;i<n;i++){
            if(selected[i]){
                for(int j=0;j<n;j++){
                    if(!selected[j] && cost[i][j]<min){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        if(u!=-1 && v!=-1){
            cout<<"Edge: ("<<u<<" - "<<v<<") cost: "<<cost[u][v]<<endl;
            minCost+=cost[u][v];
            selected[v]=1;
            edgeCount++;
        }
    }

    cout << "\nTotal cost of MST: " << minCost << endl;

    return 0;

}

/*
Enter number of vertices: 4
Enter the cost adjacency matrix (use 0 if no edge):
0 1 3 0
1 0 2 4
3 2 0 5
0 4 5 0
*/