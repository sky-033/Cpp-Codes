#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<ll>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for( lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n-1);
        lli ct=0;
        f(i,n-1){
            cin>>a[i];
            ct+=(a[i]*-1);
        }
        cout<<ct<<endl;

    }
    return 0;
}