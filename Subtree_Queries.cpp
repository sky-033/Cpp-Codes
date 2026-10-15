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


struct Node {
    long long sum;

    Node() {
        sum = 0LL;
    }
};

Node tree[4 * N];
vll adj[N];
lli in[N],out[N],flat[N];
vll val(N);
Node merge(Node a, Node b) {
    Node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

void build(long long id, long long l, long long r) {
    if (l == r) {
        tree[id].sum = flat[l];
        return;
    }

    long long mid = l + (r - l) / 2;
    build(2LL * id, l, mid);
    build(2LL * id + 1LL, mid + 1LL, r);

    tree[id] = merge(tree[2LL * id], tree[2LL * id + 1LL]);
}

void update(long long id, long long l, long long r,
            long long pos, long long val) {

    if (pos < l || pos > r) return;

    if (l == r) {
        tree[id].sum = val;
        return;
    }

    long long mid = l + (r - l) / 2;

    if (pos <= mid)
        update(2LL * id, l, mid, pos, val);
    else
        update(2LL * id + 1LL, mid + 1LL, r, pos, val);

    tree[id] = merge(tree[2LL * id], tree[2LL * id + 1LL]);
}

long long query(long long id, long long l, long long r,
                long long lq, long long rq) {

    if (lq > r || rq < l)
        return 0LL;

    if (lq <= l && r <= rq)
        return tree[id].sum;

    long long mid = l + (r - l) / 2;

    return query(2LL * id, l, mid, lq, rq) +
           query(2LL * id + 1LL, mid + 1LL, r, lq, rq);
}
lli timer=0;

void dfs(lli vertex,lli par){
    in[vertex]=++timer;
    flat[timer]=val[vertex];

    for(auto child:adj[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
    }
    out[vertex]=timer;
}

void solve(){
    lli n,q;
    cin>>n>>q;

    //build(1,1,n);
   // vll val(n);
    f(i,n){
       cin>>val[i+1]; 
    }

    f(i,n-1){
        lli a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,-1);
    build(1,1,n);

    while(q--){
        lli type;
        cin>>type;
        if(type==1){
            lli node,x;
            cin>>node>>x;
            update(1,1,n,in[node],x);
        }
        else{
            lli node;
            cin>>node;
            cout<<query(1,1,n,in[node],out[node])<<endl;
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