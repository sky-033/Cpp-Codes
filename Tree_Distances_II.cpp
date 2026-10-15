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

lli n;
vvll g;
vll depthSum_Subtree;
vll subtree;
vll ans;
void dfs1(lli vertex,lli par){
    subtree[vertex]=1;
    fa(g[vertex]){
        if(it==par) continue;
        dfs1(it,vertex);
        subtree[vertex]+=subtree[it];
        depthSum_Subtree[vertex]+=depthSum_Subtree[it]+subtree[it];
    }
}
void dfs2(lli vertex,lli par){
    fa(g[vertex]){
        if(it==par) continue;
        ans[it]=ans[vertex]+(n-subtree[it])-subtree[it];
        dfs2(it,vertex);
    }
}
void solve(){
    cin>>n;
    g.resize(n+1);
    ans.resize(n+1);
    subtree.resize(n+1,0);
    depthSum_Subtree.resize(n+1,0);
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    ans[1]=depthSum_Subtree[1];
    dfs2(1,0);
    ff(1,n+1,1) cout<<ans[i]<<" ";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}