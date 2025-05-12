#include <iostream>
using namespace std;

int n,m;
int graph[100][100];
int colour[100];

bool promising_colouring(int i){
    bool flag= true;
    for(int j=1;j<=i-1;j++){
        if(graph[i][j]==1){ //if vertices i and j are neighbours
            if(colour[i]==colour[j]){ //check colours of node i and j
                flag=false;
            }
        }
    }
    return flag;
}

void colouring(int i){
    if(promising_colouring(i)){
        if(i==n){ //if all vertices are coloured then print soln
            cout<<"Solution: ";
            for(int k=1;k<=n;k++){
                cout<<colour[k]<<" ";
            }
            cout<<endl;
        }
        else{
            int j=1;
            while(j<=m){ //for all colours m do
                colour[i+1]=j; //assign colour j to node i+1
                colouring(i+1); // recursive call
                j=j+1;
            }
        }
    }
}

int main(){
    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter number of colours: ";
    cin>>m;

    cout<<"Enter adjacency matrix: "<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
        }
    }

    //Initialize colour array
    for (int i = 1; i <= n; i++) {
        colour[i] = 0;
    }

    //Assign first node's color and start recursion
    colouring(0); // starts from node 0, color[1] will be first assigned

    return 0;
}

/*
Enter number of vertices: 4
Enter number of colours: 3
Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
*/