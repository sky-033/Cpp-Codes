#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

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
const lli N=2e5+10;
const lli INF=1e15+7;
vp g[N];
vll dist(N,INF);
vll vis(N);
 
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m,k;
    cin>>n>>m>>k;
    f(i,m){
        lli x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }
    // dijkstra(1);
    // map<lli,lli> dis,dis1;
    vp dis;
    f(i,k){
        lli s,y;
        cin>>s>>y;
        dis.push_back({s,y});
        g[1].push_back({s,y});
        g[s].push_back({1,y});
        // if(dis[s]==0) dis[s]=y;
        // if(dis[s]!=0){
        //     if(dist[s]>y && dis[s]>y) dis[s]=y;
        // }
    }
    vll indeg(n+1,0);
    dijkstra(1);
    // debug(dist);
    // ff(1,n+1,1) cout<<dist[i]<<endl;
    ff(1,n+1,1){
        lli u=i;
        fa(g[i]){
            lli v=it.first;
            lli w=it.second;
            if(u<v){
                if(dist[u]+w==dist[v]) indeg[v]++;
                if(dist[v]+w==dist[u]) indeg[u]++;
            }
        }
    }
    lli ans=0;
    fa(dis){
        if(it.second>dist[it.first]) ans++;
        else{
            if(indeg[it.first]>1){
                ans++;
                indeg[it.first]--;
            }
        }
    }
    cout<<ans<<"\n";
    // cout<<k-dis1.size()<<"\n";
    return 0;
}