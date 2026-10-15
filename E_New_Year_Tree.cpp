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
const lli N=4e5+10;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

lli in[N],out[N],flat[N],timer=0;
vll color(N);
vll g[N];

void dfs(lli node,lli parent) {
    in[node]=++timer;
    flat[timer]=color[node];
    for(auto child : g[node]){
        if(child==parent) continue;
        dfs(child,node);
    }
    out[node]=timer;
}

struct Node {
    lli mask;
    lli lazy;
    Node() {
        mask = 0LL;
        lazy = 0LL;
    }
};

Node tree[4 * N];

Node merge(Node a, Node b) {
    Node res;
    res.mask = a.mask | b.mask;
    return res;
}

void push(lli id, lli l, lli r) {
    if (tree[id].lazy == 0LL) return;

    lli val = tree[id].lazy;
    tree[id].mask = val;

    if (l != r) {
        tree[2 * id].lazy = val;
        tree[2 * id + 1].lazy = val;
    }

    tree[id].lazy = 0LL;
}

void build(lli id, lli l, lli r) {
    if (l == r) {
        tree[id].mask = (1LL << flat[l]);
        return;
    }
    lli mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
}

void update(lli id, lli l, lli r, lli ql, lli qr, lli val) {
    push(id, l, r);
    if (qr < l || r < ql) return;

    if (ql <= l && r <= qr) {
        tree[id].lazy = val;
        push(id, l, r);
        return;
    }

    lli mid = (l + r) / 2;
    update(2 * id, l, mid, ql, qr, val);
    update(2 * id + 1, mid + 1, r, ql, qr, val);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
}

lli query(lli id, lli l, lli r, lli ql, lli qr) {
    push(id, l, r);
    if (qr < l || r < ql) return 0LL;

    if (ql <= l && r <= qr)
        return tree[id].mask;

    lli mid = (l + r) / 2;
    return query(2 * id, l, mid, ql, qr) | query(2 * id + 1, mid + 1, r, ql, qr);
}

void solve(){
    lli n,m;
    cin>>n>>m;
    ff(1,n+1,1) cin>>color[i];

    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1);
    build(1,1,n);

    while(m--){
        lli type;
        cin>>type;
        if(type==1){
            lli v,c;
            cin>>v>>c;
            update(1,1,n,in[v],out[v],(1LL<<c));
        } 
        else{
            lli v;
            cin>>v;
            lli res_mask=query(1,1,n,in[v],out[v]);
            cout<<setbits(res_mask)<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t=1;
    // cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}