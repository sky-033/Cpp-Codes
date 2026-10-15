#include<bits/stdc++.h>
using namespace std;
const int ct=0;
void check(int a[],int x,int n,int &ct){
    if(n%2==0){
        if(x==n) return ;
    }
    else{
        if(x==n) return ;
    }
    sort(a,a+x);
    for(int i=0;i<n-x+1;i++){
        if(a[(x+1)/2==a[(x+1)/2 +1]]) ct+=1;
    }
    check(a,x+2,n,ct);
}
int main(){
    int t,ct=0;
    cin>>t;
    while(t--){
        int hsh[11]={0};
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            hsh[a[i]]++;
        }
        for(int i=1;i<n+1;i+=2){
            ct+=n-i+1;
        }
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]) ct++;
        }
        int x=2;
        check(a,x,n,ct);
        cout<<ct<<endl;
    }
    return 0;
}