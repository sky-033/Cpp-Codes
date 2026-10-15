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

lli n,m;
vvll g;
vll vis,par;

lli start=-1,endd=-1;
bool dfs(lli vertex){
    vis[vertex]=1;

    for(auto child:g[vertex]){
        if(!vis[child]){
            par[child]=vertex;
            if(dfs(child)) return true;
        }
        else if(vis[child]==1){
            start=child;
            endd=vertex;
            return true;
        }
    }
    vis[vertex]=2;
    return false;
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    par.resize(n+1,0);

    f(i,m){
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    ff(1,n+1,1){
        if(!vis[i]){
            if(dfs(i)) break;
        }
    }

    if(start==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    //debug(start,endd);
    vll cycle;
    cycle.push_back(start);
    while(start!=endd){
        cycle.push_back(endd);
        endd=par[endd];
    }
    cycle.push_back(start);
    reverse(all(cycle));
    cout<<cycle.size()<<endl;
    fa(cycle) cout<<it<<" ";
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