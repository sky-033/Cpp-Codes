#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
const lli N=1e5+10;
const lli M=1e9+7;

vll Size(N);
vll parent(N);
vll sum(N);
lli maxi=0;
vll a;

void make(lli v){
    parent[v]=v;
    Size[v]=1;
    sum[v]=a[v-1];
    maxi=max(maxi,a[v-1]);
}

lli find(lli v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);        //path compression
}

void Union(lli u,lli v){
    u=find(u);
    v=find(v);
    if(u!=v){
        if(Size[u]<Size[v]) swap(u,v);     //union by size
        parent[v]=u;
        Size[u]+=Size[v];
        sum[u]+=sum[v];
        maxi=max(maxi,sum[u]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    vll p(n);
    a.resize(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>p[i];
    vll ans;
    ans.push_back(0);
    reverse(all(p));
    set<lli> inserted;
    f(i,n-1){
        make(p[i]);
        if(inserted.find(p[i]+1)!=inserted.end()) Union(p[i]+1,p[i]);
        if(inserted.find(p[i]-1)!=inserted.end()) Union(p[i]-1,p[i]);
        inserted.insert(p[i]);
        ans.push_back(maxi);
    }
    reverse(all(ans));
    fa(ans) cout<<it<<" ";
    cout<<"\n";
    return 0;
}