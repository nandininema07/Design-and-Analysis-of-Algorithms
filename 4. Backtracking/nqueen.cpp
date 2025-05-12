#include<iostream>
#include<cmath>
using namespace std;

int N;
int col[100];
int solutionCount=0;

bool promising(int i){
    for(int k=1;k<i;k++){
        if(col[i]==col[k] || abs(col[i]-col[k])== abs(i-k)){
            return false;
        }
    }
    return true;
}

void nQueen(int i){
    //Solution found
    if(i>N){
        cout<<"solution: "<<++solutionCount<<" : ";
        for(int j=1; j<=N; j++){
            cout<<"("<<j<<","<<col[j]<<")";
        }
        cout<<endl;
    }
    else{
        for(int j=1;j<=N;j++){
            col[i]=j; // Place queen at column j of row i
            if (promising(i)) {
                nQueen(i+1); //Place next queen
            }
        }
    }
}

int main(){
    cout<<"Enter number of Queens: ";
    cin>>N;

    if(N<=0 || N>100){
        cout<<"Invalid N. Enter between 1 and 100";
        return 1;
    }

    nQueen(1);

    if(solutionCount==0){
        cout<<"No solution";
    }

    return 0;
}