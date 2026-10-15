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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n,k,p,cost;
    cin>>n>>k>>p>>cost;
    vll a(n);
    f(i,n) cin>>a[i];
    lli ct=0;
    if(p>k){
        lli toShift=p-k;
        vll v;
        f(i,p-1) v.push_back(a[i]);
        sort(all(v));
        lli base=0;
        f(i,toShift) base+=v[i];
        cost-=base;
        //debug(v);
        //debug(cost);
        cost-=a[p-1];
        //debug(cost);
        if(cost>=0) ct++;
    }
    else{
        cost-=a[p-1];
        if(cost>=0) ct++;
    }
    //debug(ct);
    lli shift=n-k;
    vll a2;
    f(i,n){
        if(i!=p-1) a2.push_back(a[i]);
    }
    lli cc=a[p-1];
    sort(all(a2));
    f(i,shift) cc+=a2[i];
    if(cost>=0){
        ct+=(cost/cc);
    }
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