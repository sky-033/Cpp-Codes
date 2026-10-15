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

    set<lli> par;
    map<lli,lli> mp;
    ff(1,n+1,1){
        par.insert(i);
        mp[i]=1;
    }

    DSU d;
    d.make(n);
    lli maxi=1;

    f(i,m){
        lli a,b;
        cin>>a>>b;

        if(d.find(a)==d.find(b)) cout<<par.size()<<" "<<maxi<<endl;
        
        else{
            par.erase(d.find(a));
            par.erase(d.find(b));
            
            d.Union(a,b);
            mp[d.find(a)]=d.size[d.find(a)];
            maxi=max(maxi,d.size[d.find(a)]);
            par.insert(d.find(a));
            
            cout<<par.size()<<" "<<maxi<<endl;
        }
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