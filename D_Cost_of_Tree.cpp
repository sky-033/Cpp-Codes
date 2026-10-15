#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vll a,subtree,base_cost,max_gain,height;
vll g[N];

void dfs(lli vertex,lli par=0){
    lli max_depth_1=0,max_depth_2=0;
    subtree[vertex]=a[vertex];
    for(auto child : g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree[vertex]+=subtree[child];                        
        base_cost[vertex]+=base_cost[child]+subtree[child];
        max_gain[vertex]=max(max_gain[vertex],max_gain[child]);
        height[vertex]=max(height[vertex],height[child]+1);
        max_depth_2=max(max_depth_2,height[child]+1);
        if(max_depth_2>max_depth_1) swap(max_depth_1,max_depth_2);        
    }
    for(auto child : g[vertex]){
        if(child==par) continue;
        lli mul=(height[child]+1==max_depth_1?max_depth_2:max_depth_1);
        max_gain[vertex]=max(max_gain[vertex],mul*subtree[child]);
    }
}
void solve(){
    lli n;
    cin>>n;
    a.resize(n+1);
    subtree.resize(n+1);
    base_cost.resize(n+1);
    max_gain.resize(n+1);
    height.resize(n+1);
    f(i,n) cin>>a[i+1];
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    ff(1,n+1,1) cout<<base_cost[i]+max_gain[i]<<" ";
    cout<<endl;
    ff(1,n+1,1){
        g[i].clear();
        base_cost[i]=0;
        subtree[i]=0;
        a[i]=0;
        max_gain[i]=0;
        height[i]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}