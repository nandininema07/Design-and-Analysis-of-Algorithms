//TIME COMPLEXITY: O(n^3)

#include <iostream>
using namespace std;

int main(){
    int A[3][3], B[3][3], result[3][3];

    //Input A:
    cout<<"Matrix A: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>A[i][j];
        }
    }

    //Input B:
    cout<<"Matrix B: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>B[i][j];
        }
    }

    //Initialize result to 0
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            result[i][j]=0;
        }
    }

    //Perform Multiplication
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for (int k=0;k<3;k++){
                result[i][j]+=A[i][k]* B[k][j];
            }
        }
    }

    //Output result:
    cout<<"Result: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<result[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;
}