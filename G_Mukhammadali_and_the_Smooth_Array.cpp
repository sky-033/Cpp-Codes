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

lli func(lli indx,vll &a, vll &c,lli n,vll &dp){
    if(dp[indx]!=-1) return dp[indx];
    lli ans=c[indx];
    for(lli j=0;j<indx;j++){
        if(a[indx]>=a[j]) ans=max(ans,func(j,a,c,n,dp)+c[indx]);
    }
    return dp[indx]=ans;
}

void solve(){
    lli n;
    cin>>n;
    vll a(n),c(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>c[i];
    lli total=accumulate(all(c),0LL);
    vll dp(n,-1);
    lli ans=0;
    f(i,n) ans=max(ans,func(i,a,c,n,dp));
    cout<<total-ans<<endl;
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