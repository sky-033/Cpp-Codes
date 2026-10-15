#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 

lli solve(lli i,lli j,vvll &grid,vvll &dp){
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    lli ans=0;
    if(i>0 && grid[i-1][j]==0) ans=(ans+solve(i-1,j,grid,dp))%M;
    if(j>0 && grid[i][j-1]==0) ans=(ans+solve(i,j-1,grid,dp))%M;
    return dp[i][j]=ans%M;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vvll grid(n,vll (m));
        vvll dp(n+1,vll (m+1));
        f(i,n){
            f(j,m) cin>>grid[i][j];
        }
        ff(0,n+1,1){
            for(lli j=0;j<=m;j++) dp[i][j]=-1;
        }
        if(grid[0][0]==1 || grid[n-1][m-1]==1) cout<<0<<"\n";
        else cout<<solve(n-1,m-1,grid,dp)<<"\n";
    }
    return 0;
}