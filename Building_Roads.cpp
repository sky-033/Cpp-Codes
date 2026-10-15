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
    DSU d;
    d.make(n+1);
    f(i,m){
        lli a,b;
        cin>>a>>b;
        d.Union(a,b);
    }
    lli cc=0;
    vll par;
    ff(1,n+1,1){
        if(d.find(i)==i){
            cc++;
            par.push_back(i);
        }
    }
    cout<<cc-1<<endl;
    for(lli i=1;i<(lli)par.size();i++){
        cout<<par[0]<<" "<<par[i]<<endl;
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