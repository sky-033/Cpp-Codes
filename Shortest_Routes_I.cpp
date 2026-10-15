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

vll dist(N,1e17);
vll vis(N);
vector<vector<pair<lli,lli>>> g;
void dijkstra(lli source){
    set<pair<lli,lli>> st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0){
        auto node=*st.begin();
        lli v=node.second;        
        lli dist_v=node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;
        for(auto child:g[v]){
            lli child_v=child.first;
            lli wt=child.second;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}

void solve(){
    lli n,m;
    cin>>n>>m;
    g.resize(n+1);
    f(i,m){
        lli a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
       // g[b].push_back({a,c});
    }

    dijkstra(1);

    ff(1,n+1,1) cout<<dist[i]<<" ";
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