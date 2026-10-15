#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    lli ct=0;
    vp v;
    f(i,n-1){
        map<lli,lli> mp;
        lli u=0;
        for(lli j=i;j<n;j++){
            if(mp[a[j]]==0) u++;
            else if(mp[a[j]]==1) u--;
            mp[a[j]]++;
            
            if(u==0){
                v.push_back({i,j});
            }
        }
        
    }
    if(v.size()==0){
        cout<<0<<endl;
        return;
    }
    sort(v.begin(), v.end(), [](pair<lli,lli> a, pair<lli,lli> b) {
        return a.second < b.second;    
    });
    lli r=-1;
    
    fa(v){
        if(it.first>r){
            ct++;
            r=it.second;
        }
    }
    debug(v);
    cout<<ct<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}