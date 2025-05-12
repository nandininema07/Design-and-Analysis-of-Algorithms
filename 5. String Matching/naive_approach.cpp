#include<iostream>
#include <string>
using namespace std;

void naive(string text, string pattern){
    int n=text.length();
    int m= pattern.length();

    for(int i=0;i<=n-m;i++){
        int j=0;

        while(j<m && text[i+j]==pattern[j]){
            j++;
        }

        if(j==m){
            cout<<"Pattern found at index: "<<i<<endl;
        }
    }
}

int main(){
    string text, pattern;
    cout<<"Enter text: ";
    cin>>text;
    cout<<"Enter Pattern: ";
    cin>>pattern;

    naive(text, pattern);

    return 0;
}