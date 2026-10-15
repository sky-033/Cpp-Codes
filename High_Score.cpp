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
const lli INF=1e18;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n,m;
    cin>>n>>m;

    vector<tuple<lli,lli,lli>> edges(n+1);
    vvll g(n+1);
    f(i,m){
        lli a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,-c});
        g[a].push_back(b);
    }
    vll dist(n+1,INF);
    dist[1]=0;
    // Bellman-Ford
    for(lli i=1;i<=n;i++){
        for(auto &[u,v,w]:edges){
            if(dist[u]<INF && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }

    // Detect nodes affected by negative cycle
    vector<bool> inCycle(n+1,false);
    for(auto &[u,v,w]:edges){
        if(dist[u]<INF && dist[v]>dist[u]+w){
            inCycle[v]=true;
        }
    }

    vector<bool> vis(n+1,false);
    queue<lli> q;
    for(int i=1;i<=n;i++){
        if(inCycle[i]){
            q.push(i);
            vis[i]=true;
        }
    }

    while(!q.empty()){
        lli u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }

    if(vis[n]) cout<<-1<<endl;
    else cout<<-dist[n]<<endl; 

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