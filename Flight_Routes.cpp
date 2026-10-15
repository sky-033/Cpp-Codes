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
const lli N=1e5+10;
const lli M=1e9+7;
const lli INF=1e18;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

lli n,m,k;
vector<multiset<lli>> dist;
vector<vector<pair<lli,lli>>> g;


void dijkstra(lli source){
    multiset<pair<lli,lli>> st;
    st.insert({0,source});
    dist[source].insert(0);
    while(st.size()>0){
        auto node=*st.begin();
        lli v=node.second;        
        lli dist_v=node.first;
        st.erase(st.begin());

        if(dist[v].find(dist_v)==dist[v].end()) continue;
        
        for(auto child:g[v]){
            lli child_v=child.first;
            lli wt=child.second;
            lli new_dist=dist_v+wt;
            if(dist[child_v].size()<k){
                dist[child_v].insert(new_dist);
                st.insert({new_dist,child_v});
            }
            else{
                auto it=prev(dist[child_v].end());
                if(*it>new_dist){
                    dist[child_v].erase(it);
                    dist[child_v].insert(new_dist);
                    st.insert({new_dist,child_v});
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    g.clear();
    dist.clear();
    g.resize(n+1);
    dist.resize(n+1);
    f(i,m){
        lli a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    dijkstra(1);
    
    fa(dist[n]) cout<<it<<" ";

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