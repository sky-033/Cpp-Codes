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

// #ifndef ONLINE_JUDGE
// #include "debuG.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif
string s;
lli dp[1001][1001];
lli solve(lli L,lli R){
    if(L>=R) return 0;
    if(dp[L][R]!=-1) return dp[L][R];
    lli ans;
    if(s[L]==s[R]) ans=solve(L+1,R-1);
    else ans=min(solve(L+1,R),solve(L,R-1))+1;
    return dp[L][R]=ans;
}
void solve(){
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,s.size()-1)<<endl;
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