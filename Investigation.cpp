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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vector<vector<pair<lli,lli>>> g;
vll dist;
vll vis;
vll maxi;
vll mini;
vll ways;

void dijkstra(lli source){
    set<pair<lli,lli>> st;
    st.insert({0,source});
    dist[source]=0;
    ways[1]=1;
    mini[1]=0;
    while(st.size()>0){
        auto node=*st.begin();
        lli v=node.second;        
        lli dist_v=node.first;
        st.erase(st.begin());
        // if(vis[v]) continue;
        // vis[v]=1;
        if(dist_v>dist[v]) continue;
        for(auto child:g[v]){
            lli child_v=child.first;
            lli wt=child.second;
            if(dist[v]+wt<dist[child_v]){
               // par[child_v]=v;
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
                ways[child_v]=ways[v];
                mini[child_v]=mini[v]+1;
                maxi[child_v]=maxi[v]+1;
            }
            else if(dist[v]+wt==dist[child_v]){
                ways[child_v]=(ways[child_v]+ways[v])%M;
                maxi[child_v]=max(maxi[child_v],maxi[v]+1);
                mini[child_v]=min(mini[child_v],mini[v]+1);
            }
        }
    }
}
void solve(){
    lli n,m;
    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1,INF);
    vis.resize(n+1,0);
    maxi.resize(n+1,0);
    mini.resize(n+1,1e9);
    ways.resize(n+1,0);
    f(i,m){
        lli a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    dijkstra(1);

   
    cout<<dist[n]<<" "<<ways[n]<<" "<<mini[n]<<" "<<maxi[n];

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