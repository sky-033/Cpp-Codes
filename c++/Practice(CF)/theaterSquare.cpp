#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,a;
    cin>>n>>m>>a;
    long long ct=0;
    long long x=(n+a-1)/a;
    long long y=(m+a-1)/a;
    ct=x*y;
    
    cout<<ct;
    return 0;
}