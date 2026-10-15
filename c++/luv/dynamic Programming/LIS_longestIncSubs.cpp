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

lli LIS(lli i,vll &a,vll &dp){
    if(dp[i]!=-1) return dp[i];
    lli ans=1;
    for(lli j=0;j<i;j++){
        if(a[i]>a[j]) ans=max(ans,LIS(j,a,dp)+1);
    }
    return dp[i]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vll a(n),dp(n,-1);
    f(i,n) cin>>a[i];
    lli len=0;
    f(i,n) len=max(len,LIS(i,a,dp));
    cout<<len<<endl;
    return 0;
}



