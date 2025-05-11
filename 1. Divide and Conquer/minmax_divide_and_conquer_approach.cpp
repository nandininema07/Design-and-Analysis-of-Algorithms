//TIME COMPLEXITY: O(n)
// (3n/2)-2 comparisions are required using DnC approach

#include <iostream>
using namespace std;

// pair<int, int> is used to return both max and min values.
pair<int, int> minmaxDC(int arr[], int low, int high){
    //if only one element is present in that part
    if(low==high){
        return  {arr[low], arr[low]};
    }

    //if only 2 elements are presents
    if(high==low+1){
        if(arr[low]>arr[high]){
            return {arr[low],arr[high]}; //max= low's value, min= high's value
        }
        else{
            return {arr[high], arr[low]};
        }
    }

    //Dividing string to left and right parts
    int mid= (low+high)/2;
    pair<int,int> left = minmaxDC(arr,low,mid);
    pair<int,int> right= minmaxDC(arr,mid+1,high);
    
    //minmaxDC returns {maxVal, minVal}
    int maxVal= max(left.first,right.first); //.first gives maxVal, so we compare both side's maximum
    int minVal= min(left.second,right.second); 

    return {maxVal,minVal};
}

int main(){
    int arr[7];
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter numbers of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    pair<int,int> result= minmaxDC(arr,0,n-1);

    cout<<"Max: "<<result.first<<endl;
    cout<<"Min: "<<result.second;

    return 0;
}