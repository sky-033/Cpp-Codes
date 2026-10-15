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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 
vll Size(N);
vll parent(N);

void make(lli v){
    parent[v]=v;
    Size[v]=1LL;
}

lli find(lli v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);        //path compression
}

void Union(lli a,lli b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);     //union by size
        parent[b]=a;
        Size[a]+=Size[b];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; 
    t=1;
    while(t--){
        lli n,q;
        cin>>n>>q;
        for(lli i=1;i<=n;i++) make(i);
        lli maxiWt=0;
        map<lli,vector<pair<lli,lli>>> edges;
        f(i,n-1){
            lli u,v,w;
            cin>>u>>v>>w;
            edges[w].push_back({u,v});
            maxiWt=max(maxiWt,w);
        }
        vll ans(maxiWt+1,0);
        fa(edges){
            lli wt=it.first;
            set<lli> par;
            for(auto itt:edges[wt]){
                lli u=itt.first,v=itt.second;
                Union(u,v); 
                par.insert(find(u));
                par.insert(find(v));
            }
            lli a=0;
            for(auto val:par){
                lli s=Size[val];
                a+=(s*(s-1))/2;
            }
            ans[wt]=a;
        }
        lli lastAns=0;
        ff(1,maxiWt+1,1){
            if(ans[i]!=0) lastAns=ans[i];
            else ans[i]=lastAns;
        }
        while(q--){
            lli ww;
            cin>>ww;
            if(ww>maxiWt) cout<<ans[maxiWt]<<" ";
            else cout<<ans[ww]<<" ";
        }
        cout<<endl;
    }
    return 0;
}