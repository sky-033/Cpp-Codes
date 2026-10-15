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
const lli INF=1e9;
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
    vll a(n+1);
    f(i,n) cin>>a[i+1];

    vll nextInc(n+2,INF),nextDec(n+2,INF);
    for(lli i=n-1;i>=1;i--){
        nextInc[i]=nextInc[i+1];
        nextDec[i]=nextDec[i+1];
        if(a[i]<a[i+1]) nextInc[i]=i;
        if(a[i]>a[i+1]) nextDec[i]=i;
    }

    debug(nextInc,nextDec);

    lli ans=0;
    ff(1,n+1,1){
        lli low=nextInc[i];
        lli high;
        if(low==INF) high=n;
        else high=min(nextDec[low+1],n);
        ans+=(high-i+1);
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