#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        string W;
        cin>>W;
        int n=W.size();
        string s="";
        if(n==2){
            s.push_back('i');
        }
        else{
            for(int i=0;i<n-2;i++){
                s.push_back(W[i]);
            }
            s.push_back('i');
        }
        cout<<s<<endl;
    }
    return 0;
}