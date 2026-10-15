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
const lli N=1e5+10;
const lli M=1e9+7; 

lli dp[2][N];
vll g[N];
vp lr(N);
void dfs(lli vertex,lli par=-1){
    dp[0][vertex]=dp[1][vertex]=0;
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        dp[0][vertex]+=max(dp[0][child]+abs(lr[vertex].first-lr[child].first),dp[1][child]+abs(lr[vertex].first-lr[child].second));
        dp[1][vertex]+=max(dp[0][child]+abs(lr[vertex].second-lr[child].first),dp[1][child]+abs(lr[vertex].second-lr[child].second));
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lr.resize(n+1);
        f(i,n){
            cin>>lr[i+1].first>>lr[i+1].second;
        }
        for(lli i=1;i<=n;i++) g[i].clear();
        f(i,n-1){
            lli u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        cout<<max(dp[0][1],dp[1][1])<<"\n";
    }
    return 0;
}