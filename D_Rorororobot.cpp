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
    long long maxi;

    Node() {
        maxi = 0LL;
    }
};

Node tree[4 * N];

Node merge(Node a, Node b) {
    Node ans;
    ans.maxi = max(a.maxi , b.maxi);
    return ans;
}

void build(long long id, long long l, long long r) {
    if (l == r) {
        tree[id].maxi = 0LL;
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
        tree[id].maxi = val;
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
        return tree[id].maxi;

    long long mid = l + (r - l) / 2;

    return max(query(2LL * id, l, mid, lq, rq) ,
           query(2LL * id + 1LL, mid + 1LL, r, lq, rq));
}

void solve(){
    lli n,m;
    cin>>n>>m;
    vll a(m);
    build(1,1,m);
    f(i,m){
        cin>>a[i];
        update(1,1,m,i+1,a[i]);
    }

    
    lli q;
    cin>>q;
    while(q--){
        lli x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        if(y1>y2) swap(y1,y2);
        if(((x2-x1)%k)!=0 || ((y2-y1)%k)!=0){
            no;
            continue;
        }

        x1=x1+((n-x1)/k)*k;
        lli maxii=query(1,1,m,y1,y2);
        if(maxii>=x1) no;
        else yes;
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