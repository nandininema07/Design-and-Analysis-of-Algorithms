//TIME COMPLEXITY: O(n). Follows Bottom up approach
///Using standard recursive method gives complexity O(2^n). It follows a top-down approach

#include <iostream>
using namespace std;

int main(){
    int F[100],n;
    cout<<"Enter number to find series: ";
    cin>>n;
    F[0]=0;
    F[1]=1;
    
    for(int i=2;i<n;i++){
        F[i]=F[i-2]+F[i-1];
    }

    //Print series
    for(int i=0;i<n;i++){
        cout<<F[i]<<" ";
    }
}