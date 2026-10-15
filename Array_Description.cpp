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
    lli n,m;
    cin>>n>>m;
    vll x(n);
    f(i,n) cin>>x[i];
    vll dp(m+2,0);
    if(x[0]==0){
        ff(1,m+1,1) dp[i]=1;      //if 1st element is 0 we can fill dp[i]=1 for all 1<=i<=m (since there is no last)
    }
    else{
        dp[x[0]]=1;
    }
    ff(1,n,1){
        vll next_dp(m+2,0);     //next dp which will be assigned to dp at the end          
        if(x[i]==0){
            for(lli j=1;j<=m;j++){
                next_dp[j]=(dp[j-1]+dp[j]+dp[j+1])%M;       //number of ways for next_dp[v]=(prev_dp[v-1,v,v+1]) for all 1<=v<=m
            }
        }
        else{
            lli j=x[i];
            next_dp[j]=(dp[j-1]+dp[j]+dp[j+1])%M;           //number of ways for next_dp[v]=(prev_dp[v-1,v,v+1]) for v=x[i]
        }
        dp=next_dp;
    }
    lli ans=0;
    ff(1,m+1,1){
        ans=(ans+dp[i])%M;          //sum of ways by filling by all possible m's
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