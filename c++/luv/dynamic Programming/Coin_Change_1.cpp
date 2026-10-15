#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=1e4+10;
const lli M=1e9+7; 

vll dp(N,-1);

lli func(lli amount,vll &coins){
    if(amount==0) return dp[0]=0;
    if(dp[amount]!=-1) return dp[amount];

    lli ans=1e10;
    for(auto &it : coins){
        if(amount-it>=0) ans=min(ans,func(amount-it,coins)+1);
    }
    return dp[amount]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,amount;
    cin>>n>>amount;
    vll coins(n);
    f(i,n) cin>>coins[i];
    lli req=func(amount,coins);
    if(req>=1e10) cout<<-1<<endl;
    else cout<<req<<endl;
    return 0;
}