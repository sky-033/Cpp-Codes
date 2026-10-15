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

vll g[N];

vll bfs(lli n,lli start){
    vll vis(n+1,0),dist(n+1,0);
    queue<lli> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        lli node=q.front();
        q.pop();
        fa(g[node]){
            if(vis[it]) continue;
            vis[it]=1;
            q.push(it);
            dist[it]=dist[node]+1;
        }
    }
    return dist;
}
void solve(){
    lli n;
    cin>>n;
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vll dist1=bfs(n,1);
    lli node1,node2;
    lli maxi1=*max_element(all(dist1));
    ff(1,n+1,1){
        if(dist1[i]==maxi1) node1=i;
    }
    vll dist2=bfs(n,node1);
    cout<<*max_element(all(dist2));

    
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