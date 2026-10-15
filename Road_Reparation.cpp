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
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif


struct DSU{
    vll size,parent;
    int n;
    void make(lli n){
        size.resize(n+1,1),parent.resize(n+1);
        ff(1,n+1,1) parent[i]=i;
    }
    lli find(lli v){
        if(v==parent[v]) return v;
        return parent[v]=find(parent[v]);        //path compression
    }
    void Union(lli a,lli b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);     //union by size
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};

void solve(){
    lli n,m;
    cin>>n>>m;
    vector<pair<lli,pair<lli,lli>>> edges;
    f(i,m){
        lli a,b,wt;
        cin>>a>>b>>wt;
        edges.push_back({wt,{a,b}});
    }
    sort(all(edges));
    DSU d;
    d.make(n);

    lli cost=0;

    lli times=0;
    fa(edges){
        lli a=it.second.first,b=it.second.second;
        lli wt=it.first;

        if(d.find(a)!=d.find(b)){
            d.Union(a,b);
            cost+=wt;
            times++;
        }
    }
    if(times!=n-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<cost<<endl;

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