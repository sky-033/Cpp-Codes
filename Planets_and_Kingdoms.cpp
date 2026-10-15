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
 
vvll g,g1;
vll order;
vll visited;
vll ans;
lli ct=0;
void dfs1(lli vertex){
    visited[vertex]=1;
    fa(g[vertex]){
        if(visited[it]) continue;
        dfs1(it);
    }
    order.push_back(vertex);
}
 
void dfs2(lli vertex){
    ans[vertex]=ct;
    fa(g1[vertex]){
        if(ans[it]) continue;
        dfs2(it);
    }
}
 
void solve(){
    lli n,m;
    cin>>n>>m;
    g.resize(n+1); 
    g1.resize(n+1); 
    visited.resize(n+1,0); 
    ans.resize(n+1,0); 
    f(i,m){
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g1[b].push_back(a);
    }
 
    ff(1,n+1,1){
        if(!visited[i]) dfs1(i);
    }
    reverse(all(order));
    //debug(order);
    fa(order){
        if(!ans[it]){
            ct++;
            dfs2(it);
        }
    }
    cout<<ct<<endl;
    ff(1,n+1,1) cout<<ans[i]<<" ";
    cout<<endl;
 
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
