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
    vector<vector<char>> a(n,vector<char> (n));
    vvll dp(n,vll (n));
    f(i,n){
        f(j,n){
            cin>>a[i][j];
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    f(i,n){
        f(j,n){
            if(i-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
            if(j-1>=0) dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
            if(a[i][j]=='*') dp[i][j]=0;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
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