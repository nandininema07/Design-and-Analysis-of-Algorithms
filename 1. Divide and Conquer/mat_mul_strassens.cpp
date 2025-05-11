//TIME COMPLEXITY: O(n^2.81)

#include <iostream>
using namespace std;

void strassen(int A[2][2], int B[2][2], int result[2][2]){
    int a,b,c,d,e,f,g,h; 
    int P1,P2,P3,P4,P5,P6,P7;
    int r,s,t,u;
    a=A[0][0];
    b=A[0][1];
    c=A[1][0];
    d=A[1][1];

    e=B[0][0];
    f=B[0][1];
    g=B[1][0];
    h=B[1][1];

    P1= a*(f-g);
    P2= (a+b)*h;
    P3= (c+d)*e;
    P4= d*(g-e);
    P5= (a+d)*(e+h);
    P6= (b-d)*(g+h);
    P7= (a-c)*(e+f);

    r=P5+P4-P2+P6;
    s=P1+P2;
    t=P3+P4;
    u=P5+P1-P3-P7;

    result[0][0]=r;
    result[0][1]=s;
    result[1][0]=t;
    result[1][1]=u;

}

int main(){
    int A[2][2], B[2][2], result[2][2];

    //Input A:
    cout<<"Matrix A: "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>A[i][j];
        }
    }

    //Input B:
    cout<<"Matrix B: "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>B[i][j];
        }
    }

    strassen(A,B,result);
    cout<<"Strassen's Multiplication Result: "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}