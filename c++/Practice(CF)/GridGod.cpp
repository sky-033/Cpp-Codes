#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,x;
    cin>>n>>x;
    lli ct=0;
    for(lli i=1;i<=n;i++){
        if(x%i==0 && x/i<=n){
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
}