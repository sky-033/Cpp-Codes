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
const lli N=3e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vll g[N];
vll vis;
vll parent;
vll subtree;
vll ans;
void dfs(lli vertex,lli par=-1){
    parent[vertex]=par;
    for(auto child : g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree[vertex]+=subtree[child];
    }
}
void bfs(lli source){
    vis[source]=1;         
    queue<lli> q;
    q.push(source);
    while(!q.empty()){
        lli cur_v=q.front();
        q.pop();
        if(cur_v!=0){
            lli pari=parent[cur_v];
            ans[cur_v]=((subtree[cur_v]-1)*2+1+ans[pari])%M;
        }
        for(auto child:g[cur_v]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
            }
        }
    }

}
void clear_all(lli n){
    ff(0,n+1,1){
        g[i].clear();
    }
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    subtree.assign(n+1,1);
    ans.assign(n+1,0);
}

void solve(){
    lli n;
    cin>>n;
    clear_all(n+1);
    g[0].push_back(1);
    g[1].push_back(0);
    f(i,n){
        lli x,y;
        cin>>x>>y;
        if(x!=0){
            g[i+1].push_back(x);
            g[x].push_back(i+1);
        }
        if(y!=0){
            g[i+1].push_back(y);
            g[y].push_back(i+1);
        }
    }
    dfs(0);
    bfs(0);
    // debug(subtree);
    ff(1,n+1,1) cout<<ans[i]<<" ";
    cout<<endl;
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