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

lli n;
bool check(vp &fre,lli mid){
    lli ct=0;
    f(i,n){
        lli a=fre[i].first,b=fre[i].second;
        if(b>=ct && a>=mid-1-ct) ct++;
    }
    return ct>=mid;
}
void solve(){
    cin>>n;

    vp fre;

    f(i,n){
        lli a,b;
        cin>>a>>b;
        fre.push_back({a,b});
    }

    lli l=0,h=n,mid;

    while(h-l>1){
        mid=(l+h)/2;
        if(check(fre,mid)) l=mid;
        else h=mid-1;
    }

    if(check(fre,h)) cout<<h<<endl;
    else cout<<l<<endl;



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