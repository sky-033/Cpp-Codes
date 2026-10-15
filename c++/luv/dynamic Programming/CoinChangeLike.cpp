#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
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

lli dp[301][301];

lli poww(lli a,lli b){
    lli ans=1;
    for(lli i=0;i<b;i++) ans*=a;
    return ans;
}

lli func(lli indx,lli amount,lli x){
    if(amount==0) return 1;
    if(amount<0) return 0;
    lli val=poww(indx,x);
    if(val>amount) return 0;
    if(dp[indx][amount]!=-1) return dp[indx][amount];
    lli ways=(func(indx+1,amount-val,x)+func(indx+1,amount,x))%M;
    return dp[indx][amount]=ways;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,x;
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    cout<<func(1,n,x)<<endl;
    return 0;
}