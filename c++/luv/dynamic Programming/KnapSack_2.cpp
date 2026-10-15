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

vll wt(101),val(101);
lli dp[101][100001];

lli func(lli indx,lli value_left){
    if(value_left==0) return 0;
    if(indx<0) return 1e18;
    if(dp[indx][value_left]!=-1) return dp[indx][value_left];
    lli ans=func(indx-1,value_left);
    if(value_left-val[indx]>=0) ans=min(ans,func(indx-1,value_left-val[indx])+wt[indx]);
    return dp[indx][value_left]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    lli n,w;
    cin>>n>>w;
    lli max_value=0;
    f(i,n){
        cin>>wt[i]>>val[i];
        max_value+=val[i];
    }
    for(lli i=max_value;i>=0;i--){
        if(func(n-1,i)<=w){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}