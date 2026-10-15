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
    lli n,k;
    cin>>n>>k;
    vll a(n);
    map<lli,lli> mp;
    f(i,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    set<lli> seen;
    lli first=a[0];
    vp mp2;
    fa(mp){
        if(it.first!=a[0]){
            mp2.push_back({it.second,it.first});
        }
    }
    sort(all(mp2));
    debug(mp,mp2);
    lli erase=0;
    fa(mp2){
        if(it.first<=k){
            erase++;
            k-=it.first;
        }
        else break;
    }
    cout<<1+mp2.size()-erase<<endl;

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