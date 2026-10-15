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
const lli N=1e5+10;
const lli M=1e9+7; 
lli k;
vll dp(N,-1),hi(N);
lli calc(lli i){
    if(i==0) return dp[0]=0;
    if(dp[i]!=-1) return dp[i];
    lli cost=1e18;
    for(lli j=1;j<=k;j++){
        if(i-j>=0) cost=min(cost,calc(i-j)+abs(hi[i]-hi[i-j]));
    }
    return dp[i]=cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n>>k;
    f(i,n) cin>>hi[i];
    cout<<calc(n-1)<<endl;
    return 0;
}