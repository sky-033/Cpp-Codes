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

lli dp[1005];
lli func(lli len,vll &prices){
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];
    lli ans=0;
    ff(1,prices.size()+1,1){
        if(len-i>=0) ans=max(ans,func(len-i,prices)+prices[i-1]);
    }
    return dp[len]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    lli n;   
    cin>>n;
    vll prices(n);
    f(i,n) cin>>prices[i];
    cout<<func(n,prices)<<endl;
    return 0;
}