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
const lli INF = 1e18;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vector<vector<pair<lli,lli>>> g;

// dist[node][0 or 1]

vector<array<lli,2>> dist(N);
vector<array<bool,2>> vis(N);

void dijkstra(lli source){
    set<tuple<lli,lli,lli>> st; // {dist, node, usedDiscount}

    dist[source][0]=0;
    dist[source][1]=INF;

    st.insert({0,source,0});

    while(st.size()>0){
        auto node=*st.begin();
        st.erase(st.begin());
        lli d=get<0>(node);
        lli v=get<1>(node);
        lli used=get<2>(node);
        if(vis[v][used]) continue;
        vis[v][used]=1;
        for(auto child:g[v]){
            lli child_v=child.first;
            lli wt=child.second;
            // normal edge
            if(dist[v][used]+wt < dist[child_v][used]){
                dist[child_v][used]=dist[v][used]+wt;
                st.insert({dist[child_v][used],child_v,used});
            }
            // use discount
            if(used==0){
                if(dist[v][0]+wt/2 < dist[child_v][1]){
                    dist[child_v][1]=dist[v][0]+wt/2;
                    st.insert({dist[child_v][1],child_v,1});
                }
            }
        }
    }
}

void solve(){
    lli n,m;
    cin>>n>>m;
    g.resize(n+1);

    ff(1,n+1,1){
        dist[i][0]=dist[i][1]=INF;
        vis[i][0]=vis[i][1]=0;
    }
    f(i,m){
        lli a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    dijkstra(1);
    cout<<min(dist[n][0],dist[n][1])<<endl;
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