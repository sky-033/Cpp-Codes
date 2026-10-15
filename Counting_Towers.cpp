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
const lli N=1e6+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

lli dp[N][2];

void precompute(){
    dp[1][0]=1;
    dp[1][1]=1;
    ff(2,N,1){
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%M;
        dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%M;
    }
}

void solve(){
    lli n;
    cin>>n;
    cout<<(dp[n][0]+dp[n][1])%M<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    precompute();
    while(t--){
        solve();
    }
    return 0;
}