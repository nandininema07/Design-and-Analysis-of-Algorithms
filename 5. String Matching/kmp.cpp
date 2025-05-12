#include<iostream>
#include<string>
#include<vector>
using namespace std;

void computeLSP(const string& pattern, vector<int>& lps){
    int m=pattern.length();
    int len=0;
    lps[0]=0;

    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len !=0){
                len= lps[len-1];
            }
            else{
                lps[i++]=0;
            }
        }
    }
    
}

void KMPSearch(const string& text, const string& pattern){
    int n=text.length();
    int m=pattern.length();

    vector<int> lps(m);

    computeLSP(pattern,lps);

    int i=0;
    int j=0;
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }

        if(j==m){
            cout<<"Pattern found at index: "<<(i-j)<<endl;
            j=lps[j-1];
        }
        else if(i<n && pattern[j] != text[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

int main(){
    string text, pattern;
    cout<<"Enter text: ";
    cin>>text;
    cout<<"Enter Pattern: ";
    cin>>pattern;

    KMPSearch(text, pattern);

    return 0;
}