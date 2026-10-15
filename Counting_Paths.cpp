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
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vll adj[N];
lli up[N][LOG];
lli depth[N];
lli ct[N];

void dfs(lli v,lli parent){
    up[v][0]=parent;
    for(lli k=1;k<LOG;k++){
        if(up[v][k-1]!=-1) up[v][k]=up[up[v][k-1]][k-1];
        else up[v][k] = -1;
    }
    for(auto child : adj[v]){
        if(child==parent) continue;
        depth[child]=depth[v]+1;
        dfs(child,v);
    }
}

lli getKthAncestor(lli v,lli k){
    for(lli j=0;j<LOG;j++){
        if(k &(1<<j)){
            v=up[v][j];
            if(v==-1) break;
        }
    }
    return v;
}

lli lca(lli u, lli v){
    if(depth[u]<depth[v]) swap(u,v);

    lli diff=depth[u]-depth[v];
    u=getKthAncestor(u, diff);
    if(u==v) return u;

    for(lli j=LOG-1;j>=0;j--){
        if(up[u][j]!=-1 && up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}

void dfs2(lli vertex,lli par){
    for(auto child:adj[vertex]){
        if(child==par) continue;
        dfs2(child,vertex);
        ct[vertex]+=ct[child];
    }
}

void solve(){
    lli n,m;
    cin>>n>>m;

    f(i,n-1){
        lli a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ff(1,n+1,1){
        f(j,30) up[i][j]=-1;
    }

    dfs(1,-1);

    while(m--){
        lli a,b;
        cin>>a>>b;

        lli anc=lca(a,b);
        ct[a]++,ct[b]++;
        ct[anc]--;
        if(up[anc][0]!=-1) ct[up[anc][0]]--;

    }

    dfs2(1,-1);

    ff(1,n+1,1) cout<<ct[i]<<" ";
    cout<<endl;

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