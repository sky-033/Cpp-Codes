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

void solve(){
    lli n,m;
    cin>>n>>m;
    vector<tuple<lli,lli,lli>> edges;
    f(i,m){
        lli a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    vll dist(n+1,0);
    vll parent(n+1,-1);
    lli x=-1;

    ff(1,n+1,1){
        for(auto &[u,v,w] : edges){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                if(i==n) x=v;
            }
        }
    }

    if(x==-1){
        no;
        return;
    }

    f(i,2*n) x=parent[x];

    vll cycle;
    lli cur=x;

    do{
        cycle.push_back(cur);
        cur=parent[cur];
    }while(cur!=x);

    cycle.push_back(x);
    reverse(all(cycle));

    yes;
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