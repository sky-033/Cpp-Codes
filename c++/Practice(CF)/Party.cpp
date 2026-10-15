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
const lli N=2e5+10;
const lli M=1e9+7; 

vll Size(N);
vll parent(N);

void make(lli v){
    parent[v]=v;
    Size[v]=1;
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
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n, k;
    cin>>n>>k;
    ff(1,n+1,1) make(i);
    f(i,k){
        lli u,v;
        cin>>u>>v;
        Union(u,v);
    }
    set<lli> par;
    ff(1,n+1,1){
        if(find(i)==i) par.insert(i);
    }

    lli m;
    cin>>m;
    f(i,m){
        lli u,v;
        cin>>u>>v;
        if(find(u)==find(v)){
            if(par.find(find(u))!=par.end()) par.erase(find(u));
        }
    }
    lli maxi=0;
    fa(par) maxi=max(maxi,Size[it]);
    cout<<maxi<<"\n";
    return 0;
}