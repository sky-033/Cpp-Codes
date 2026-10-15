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

lli in[N],out[N],timer=0;
vll g[N];

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


void dfs(int node, int parent) {
    in[node]=++timer;
    for(auto child : g[node]){
        if(child==parent) continue;
        dfs(child,node);
    }
    out[node]=timer;
}
void solve(){
    lli n,q;
    cin>>n>>q;
    vll val(n+1);
    ff(1,n+1,1) cin>>val[i];
    
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    FenwickTree ft(n);

    ff(1,n+1,1){
        ft.update(in[i],val[i]);
        ft.update(out[i]+1,-val[i]);
    }
    while(q--){
        lli type;
        cin>>type;
        if(type==1){
            lli node,newVal;
            cin>>node>>newVal;
            lli diff=newVal-val[node];
            val[node]=newVal;
            ft.update(in[node],diff);
            ft.update(out[node]+1,-diff);
        }
        else{
            lli node;
            cin>>node;
            cout<<ft.query(in[node])<<endl;
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