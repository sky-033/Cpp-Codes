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
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
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
    lli n,m;
    cin>>n>>m;
    lli ii=1;
    set<pair<lli,lli>> a;
    f(i,n){
        lli x;
        cin>>x;
        a.insert({x,ii});
        ii++;
    }
    vll b,c;
    vp mons,mons1;
    f(i,m){
        lli b1;
        cin>>b1;
        b.push_back(b1);
        
    }
    f(i,m){
        lli c1;
        cin>>c1;
        c.push_back(c1);
    }
    f(i,m){
        lli b1=b[i],c1=c[i];
        if(c1>0) mons.push_back({b1,c1});
        else  mons1.push_back({b1,c1});
    }

    if(mons.size()>0) sort(all(mons));
    if(mons1.size()>0) sort(all(mons1));
    lli mons_idx=0;
    lli mons1_idx=0;
    lli ct=0;
    
    while(a.size()>0){
        auto it1=a.begin();
        lli a1=it1->first;
        a.erase(it1);
        if(mons_idx<mons.size() && mons[mons_idx].first<=a1){
            a1=max(a1,mons[mons_idx].second);
            a.insert({a1,ii});
            ii++;
            ct++;
            mons_idx++;
        }
        else if(mons1_idx<mons1.size() && mons1[mons1_idx].first<=a1){
            ct++;
            mons1_idx++;
        }
    }
    cout<<ct<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}