#include <iostream>
using namespace std;

int main() {
    int numbers[7];
    int n= sizeof(numbers)/ sizeof(numbers[0]);
    cout<<"Enter numbers of array: ";
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }

    int min=numbers[0];
    int max=numbers[0];

    for(int i=1;i<n;i++){
        if(numbers[i]>=max){
            max= numbers[i];
        }
        else if(numbers[i]<= min){
            min=numbers[i];
        }
    }

    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min;   

    return 0;
}