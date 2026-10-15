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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
const lli N=101;
const lli M=1e9+7; 
vector<vector<pair<lli,lli>>> g;
vll subtree(N);
void dfs(lli vertex,lli par=-1){
    // if(par!=-1) subtree[par]+=subtree[vertex]+g[par][vertex].second;
    for(auto child:g[vertex]){
        if(child.first==par) continue;
        dfs(child.first,vertex);
        subtree[vertex]=max(subtree[child.first]+child.second,subtree[vertex]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    g.resize(n);
    f(i,n-1){
        lli u,v,c;
        cin>>u>>v>>c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
    dfs(0);
    cout<<subtree[0]<<"\n";
    return 0;
}