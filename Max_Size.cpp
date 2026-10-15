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
const lli N_MAX = 2e5+10;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

struct Node{
    lli sum;
    lli cnt;
    Node(){
        sum=0LL;
        cnt=0LL;
    }
};

Node tree[4*N_MAX];

Node merge(Node a, Node b){
    Node ans;
    ans.sum=a.sum+b.sum;
    ans.cnt=a.cnt+b.cnt;
    return ans;
}

void build(lli id,lli l,lli r){
    if(l==r){
        tree[id]=Node();
        return;
    }
    lli mid=l+(r-l)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

void update(lli id,lli l,lli r,lli val){
    if(l==r){
        tree[id].cnt++;
        tree[id].sum+=l; 
        return;
    }
    lli mid=l+(r-l)/2;
    if(val<=mid) update(2*id,l,mid,val);
    else update(2*id+1,mid+1,r,val);
    tree[id]=merge(tree[2*id],tree[2*id+1]);
}

lli query_walk(lli id,lli l,lli r,lli Y){
    if(Y<=0) return 0;
    if(l==r){
        return min(tree[id].cnt, Y/l);
    }
    lli mid=l+(r-l)/2;
    if(tree[2*id].sum<=Y){
        return tree[2*id].cnt+query_walk(2*id+1,mid+1,r,Y-tree[2*id].sum);
    } 
    else{
        return query_walk(2*id,l,mid,Y);
    }
}

struct Query{
    lli x,y,id;
};

void solve(){
    lli n,q;
    cin>>n>>q;
    vll a(n);
    f(i,n) cin>>a[i];

    vector<Query> queries(q);
    f(i,q){
        cin>>queries[i].x>>queries[i].y;
        queries[i].id=i;
    }
    sort(all(queries),[](Query a,Query b){
        return a.x < b.x;
    });
    build(1,1,n);
    vll ans(q);
    lli current_x=0;
    f(i,q){
        while(current_x<queries[i].x){
            update(1,1,n,a[current_x]);
            current_x++;
        }
        ans[queries[i].id]=query_walk(1,1,n,queries[i].y);
    }
    f(i,q) cout<<ans[i]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}