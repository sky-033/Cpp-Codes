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

vll g[N];
lli in[N],out[N],flat[N],timer=0;
vll color(N);
void dfs(int node, int parent) {
    in[node]=++timer;
    flat[timer]=color[node];
    for(auto child : g[node]){
        if(child==parent) continue;
        dfs(child,node);
    }
    out[node]=timer;
}
class FenwickTree {
    long long n;
    vector<long long> bit; // BIT array

public:
    FenwickTree(long long n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Add value 'val' at index 'i'
    void update(long long i, long long val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    // Get sum from 1 to i
    long long query(long long i) {
        long long sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    // Get sum from l to r
    long long rangeQuery(long long l, long long r) {
        return query(r) - query(l - 1);
    }
};

void solve(){
    lli n;
    cin>>n;
    f(i,n){
        cin>>color[i+1];
    }
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);
    map<lli,lli> mp;

    FenwickTree ft(n);

    vector<vp> queries(n+1);

    ff(1,n+1,1){
        queries[out[i]].push_back({in[i],i});
    }

    vll ans(n+1,0);
    ff(1,n+1,1){
        lli c=flat[i];

        if(mp.count(c)){
            ft.update(mp[c],-1);
        }

        mp[c]=i;
        ft.update(i,1);

        for(auto it : queries[i]){
            lli st=it.first,node=it.second,end=i;

            ans[node]=ft.rangeQuery(st,end);
        }

    }
    ff(1,n+1,1) cout<<ans[i]<<" ";

    
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