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
    lli n,ax,ay,bx,by;
    cin>>n>>ax>>ay>>bx>>by;
    vll x(n),y(n);
    f(i,n) cin>>x[i];
    f(i,n) cin>>y[i];
    map<lli,lli> mini,maxi;
    maxi[ax]=mini[ax]=ay;
    maxi[bx]=mini[bx]=by;
    lli dp[n+3][2];
    f(i,n){
        if(mini.count(x[i])==0) mini[x[i]]=maxi[x[i]]=y[i];
        else{
            mini[x[i]]=min(mini[x[i]],y[i]);
            maxi[x[i]]=max(maxi[x[i]],y[i]);
        }
    }
    lli start=ax,grp=0;
    // debug(maxi,mini);
    fa(maxi){
        if(it.first==ax){
            dp[0][0]=dp[0][1]=0;
            continue;
        }
        lli same_grp_dist=(it.first-start)+(maxi[it.first]-mini[it.first]);
        grp++;  
        dp[grp][0]=min(dp[grp-1][0]+abs(maxi[it.first]-mini[start]),dp[grp-1][1]+abs(maxi[it.first]-maxi[start]))+same_grp_dist;
        dp[grp][1]=min(dp[grp-1][0]+abs(mini[it.first]-mini[start]),dp[grp-1][1]+abs(mini[it.first]-maxi[start]))+same_grp_dist;
        start=it.first;
    }
    cout<<dp[grp][0]<<'\n';
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