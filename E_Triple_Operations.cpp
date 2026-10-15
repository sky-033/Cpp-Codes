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

vll count1(N),prefix(N);

void precompute(){
    ff(1,N,1){
        lli val=i,ct=0;
        while(val>0){
            ct++;
            val/=3;
        }
        count1[i]=ct;
    }
    ff(1,N,1) prefix[i]=prefix[i-1]+count1[i];
}
void solve(){
    lli l,r;
    cin>>l>>r;
    lli L=l,R=r,ct=0;
    
    while(L>0){
        L/=3;
        R*=3;
        ct++;
    }
    while(R>0){
        ct++;
        R/=3;
    }

    r--;
    ct+=prefix[r]-prefix[l];
    cout<<ct<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    precompute();
    while(t--){
        solve();
    }
    return 0;
}