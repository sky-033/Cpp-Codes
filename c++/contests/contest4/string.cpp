#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'==1) x++;
            
        }
        cout<<x<<endl;
    }
    return 0;
}