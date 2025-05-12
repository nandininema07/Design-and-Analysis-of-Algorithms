#include<iostream>
#include<vector>
using namespace std;

int n, targetSum;
vector<int> weights;
vector<int> X; //X[i] = 1 means included, 0 means excluded

bool promising(int i, int weight, int total){
    return(weight+total>=targetSum) && (weight<=targetSum);
}

void sumOfSubsets(int i, int weight, int total){
    //Solution found
    if(promising(i,weight,total)){
        if(weight==targetSum){
            cout<<"Subset: ";
            for(int j=1;j<=i;j++){
                if(X[j]==1){
                    cout<<weights[j]<<" ";
                }
            }
            cout<<endl;
        }
        else if(i<n){
        X[i+1]=1;
        sumOfSubsets(i+1, weight+weights[i+1], total-weights[i+1]);

        X[i+1]=0;
        sumOfSubsets(i+1, weight, total-weights[i+1]);
        }
    }  
}

int main(){
    cout<<"Enter number of weights: ";
    cin>>n;

    weights.resize(n+1);
    X.resize(n+1,0);

    int total=0;
    cout<<"Enter weights to be included: ";
    for(int i=1;i<=n;i++){
        cin>>weights[i];
        total+=weights[i];
    }

    cout<<"Target sum: ";
    cin>>targetSum;

    cout<<"Subsets with sum "<<targetSum<<": \n";
    sumOfSubsets(0,0,total);

    return 0;
}

/*
Enter number of items: 4
Enter item weights: 10 7 5 18
Enter target sum: 22
*/