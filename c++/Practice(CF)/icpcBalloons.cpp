#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int hsh[26]={0};
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ct=0;
        for(int i=0;i<n;i++){
            hsh[s[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(hsh[i]>0){
                hsh[i]-=1;
                ct+=2;
            }
        }
        for(int i=0;i<26;i++){
            ct+=hsh[i];
        }
        cout<<ct<<endl;
    }
    return 0;
}