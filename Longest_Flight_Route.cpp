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
const lli INF=-1e12;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
lli n,m;
vll dist;
vll vis;
vll par;
vvll g;

void topoSort(int V, vvll  &adj) {
    vll indegree(V+1,0);
    ff(1,V+1,1){
        fa(adj[i]) indegree[it]++;  
    } 
    queue<lli> q;
    ff(1,V+1,1){
        if(indegree[i]==0) q.push(i);
    }
    vll topo;
    dist[1]=0;
    while(!q.empty()){
        lli node = q.front();
        q.pop();
        topo.push_back(node);
        fa(adj[node]){
            if(dist[node]!=INF && dist[it]<dist[node]+1){
                dist[it]=dist[node]+1;
                par[it]=node;
            }
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
}

void solve(){
    cin>>n>>m;
    dist.assign(n+1,INF);
    vis.assign(n+1,0);
    g.resize(n+1);
    par.assign(n+1,0);
    f(i,m){
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    
    //debug(par);
    topoSort(n,g);
    if(dist[n]==-1e12) cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<dist[n]+1<<endl; 
        lli st=n,endd=1;
        vll path;
        path.push_back(st);
        while(st!=endd){
            st=par[st];
            path.push_back(st);
        }
        reverse(all(path));
        fa(path) cout<<it<<" ";
        //debug(path);
    }
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