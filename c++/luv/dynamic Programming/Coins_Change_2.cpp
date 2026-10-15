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
const lli N=2e5+10;
const lli M=1e9+7; 

lli dp[310][10010];

lli func(lli indx,lli amount,vll &coins){
    if(amount==0) return 1;
    if(indx<0) return 0;
    if(dp[indx][amount]!=-1) return dp[indx][amount];
    lli ways=0;
    for(lli i=0;i<=amount;i+=coins[indx]){
        ways+=func(indx-1,amount-i,coins);
    }
    return dp[indx][amount]=ways;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    lli n,amount;
    cin>>n>>amount;
    vll coins(n);
    f(i,n) cin>>coins[i];
    cout<<func(n-1,amount,coins);        //(n-1)th index tak ke coins ko use krke kitna ways aaya
    return 0;
}