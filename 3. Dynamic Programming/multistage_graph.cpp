#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

//vector<vector<int>> is a 2D vector (a vector of vectors)- used here to represent adjacency matrix of graph
//& means graph is passed by reference

int multiStage(vector<vector<int>>& graph, int n){
    vector<int> MSG(n,0); // creates a 1D vector MSG of size n, where each element is initialized to 0

    //MSG[i] stores the minimum cost from each node to the destination
    MSG[n-1]=0; //cost of last node=0

    for(int i=n-2;i>=0;i--){
        MSG[i]=INT_MAX;
        for(int j=i+1;j<n;j++){
            if(graph[i][j]!=0 && MSG[j]!= INT_MAX){
                // graph[i][j] = cost of going from node i to node j
                MSG[i]= min(MSG[i],graph[i][j]+MSG[j]); //MSG[j]= minumum cost to reach destination from node j
            }
        }
    }

    return MSG[0]; //return min cost to reach destination from 1st node
}

int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout<<"Enter adjacency matrix (use 0 if no edge): "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    int cost= multiStage(graph,n);
    if(cost==INT_MAX){
        cout<<"No path";
    }
    else{
        cout<<"Minimum cost from source to destination: "<<cost<<endl;
    }

    return 0;
}
/*
Enter number of nodes: 4
Enter adjacency matrix (use 0 if no edge): 
0 10 75 0
0 0 95 40
0 0 0 60
0 0 0 0
*/