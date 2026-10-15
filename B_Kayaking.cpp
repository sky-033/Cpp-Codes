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
    lli n;
    cin>>n;
    vll a(2*n);
    f(i,2*n) cin>>a[i];
    sort(all(a));
    lli ans=1e18;
    f(i,2*n){
        for(lli j=i+1;j<2*n;j++){
            vll rest;
            f(k,2*n){
                if(i==k || j==k) continue;
                rest.push_back(a[k]);
            }
            lli val=0;
            for(lli st=0;st<2*n-2-1;st+=2){
                val+=rest[st+1]-rest[st];
            }
            ans=min(ans,val);
        }
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}