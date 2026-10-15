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
lli n,m;
lli solve(lli i,lli j,vvll &grid,vvll &dp){
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(grid[i][j]==1) return dp[i][j]=0;

    lli right=solve(i,j+1,grid,dp);
    lli down=solve(i+1,j,grid,dp);
    lli diag=solve(i+1,j+1,grid,dp);

    return dp[i][j]=1+min({right,down,diag});
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vvll grid(n,vll(m));
        vvll dp(n+1,vll(m+1,-1));
        f(i,n){
            f(j,m) cin>>grid[i][j];
        }
        lli maxSide=0;
        f(i,n){
            f(j,m){
                maxSide=max(maxSide,solve(i,j,grid,dp));
            }
        }
        cout<<maxSide*maxSide<<"\n";
    }
    return 0;
}