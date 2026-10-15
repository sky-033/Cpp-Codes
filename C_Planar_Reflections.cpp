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
const lli N=1001;
const lli K=1001;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vvll dp;
lli n;
lli rec(lli i,lli j){
    if(i==0 || j==1) return 1;

    if(dp[i][j]!=-1) return dp[i][j];
    lli ans=((rec(i-1,j)%M)+(rec(n-i,j-1)%M))%M;

    return dp[i][j]=ans;
}
void solve(){
    lli k;
    cin>>n>>k;
    dp.assign(n+1,vll(k+1,-1));

    cout<<rec(n,k)<<endl;
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