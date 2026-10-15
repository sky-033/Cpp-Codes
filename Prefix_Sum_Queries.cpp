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

vll a;

struct Node {
    long long sum,prefix;

    // Node() {
    //     sum = 0LL;
    //     prefix = 0LL;
    // }
};

Node tree[4 * N];

Node merge(Node a, Node b) {
    Node ans;
    ans.sum = a.sum + b.sum; 
    ans.prefix=max(a.prefix,b.prefix+a.sum);
    return ans;
}

void build(long long id, long long l, long long r) {
    if (l == r) {
        tree[id].sum = a[l];
        tree[id].prefix = max(0LL,a[l]);
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
        tree[id].prefix = max(0LL, val);
        return;
    }

    long long mid = l + (r - l) / 2;

    if (pos <= mid)
        update(2LL * id, l, mid, pos, val);
    else
        update(2LL * id + 1LL, mid + 1LL, r, pos, val);

    tree[id] = merge(tree[2LL * id], tree[2LL * id + 1LL]);
}

Node query(long long id, long long l, long long r,
                long long lq, long long rq) {

    if (lq > r || rq < l)
        return {0LL,0LL};

    if (lq <= l && r <= rq)
        return tree[id];

    long long mid = l + (r - l) / 2;

    return merge(query(2LL * id, l, mid, lq, rq) ,
           query(2LL * id + 1LL, mid + 1LL, r, lq, rq));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,q;
    cin>>n>>q;
    a.resize(n+1);
    f(i,n) cin>>a[i+1];
    build(1,1,n);
    while(q--){
        lli ch;
        cin>>ch;
        if(ch==1){
            lli k,x;
            cin>>k>>x;
            update(1,1,n,k,x);
        }
        else{
            lli a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b).prefix<<endl;
        }
    }
    
    return 0;
}