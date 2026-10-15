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
#define sor(x) sort(all(x))
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
    lli n;
    cin>>n;
    vll a(n+1);
    ff(1,n+1,1) cin>>a[i];
    lli maxi=-1;
    ff(1,n+1,1){
        maxi=max(maxi,a[i]);
        if(i%2==0) a[i]=maxi;
    }
    lli ct=0;
    ff(2,n+1,2){
        lli val=0;
        lli m=0;
        if(i+1<=n){
            if(a[i+1]-a[i]>=0){
                m+=a[i+1]-a[i]+1;
                a[i+1]=a[i]-1;
            }
        }
        if(a[i-1]-a[i]>=0){
            m+=a[i-1]-a[i]+1;
            a[i-1]=a[i]-1;
        }
        ct+=m;
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