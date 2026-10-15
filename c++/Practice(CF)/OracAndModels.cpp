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

lli dp[N];
lli n;
lli func(lli indx,vll &a){
    if(dp[indx]!=-1) return dp[indx];
    lli ans=1;
    for(lli j=2*indx;j<=n;j+=indx){
        if(a[j]>a[indx])ans=max(ans,func(j,a)+1);
    }
    return dp[indx]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        vll a(n+1);
        ff(1,n+1,1) cin>>a[i];
        lli ans=1;
        ff(1,n+1,1) ans=max(ans,func(i,a));
        cout<<ans<<endl;
    }
    return 0;
}