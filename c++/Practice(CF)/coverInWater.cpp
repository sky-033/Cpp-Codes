#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c=0;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                c++;
            }
            else{
                c=0;
            }
            if(c>2){
                flag=true;
                break;
            }
        }
        if(flag==true) cout<<2<<endl;
        else{
            int ct=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='.') ct++;
            }
            cout<<ct<<endl;
        }
    }
    return 0;
}