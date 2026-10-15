#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int minSec=1;
        if(n==1){
            minSec=1;
        }
        else{
            minSec+=(n-1)*k;
        }
        cout<<minSec<<endl;
    }
    return 0;
}