#include<bits/stdc++.h>
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
const lli N=1e5+10;
const lli M=1e9+7; 


vll g[N];
vll height(N);
vll parent(N);
map<pair<lli, lli>, lli> pairs;
vector<pair<lli, lli>> edge_order;
void dfs(lli vertex,lli par=-1){
    parent[vertex]=par;
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        edge_order.push_back({u,v});
        pairs.emplace(make_pair(u, v),-1);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    // cout<<height[1]<<" ";
    set<pair<lli,lli>> ht;
    ff(1,n+1,1){
        ht.insert({height[i],i});
    }
    lli mex=0;
    ff(1,n+1,1){
        if(g[i].size()==1){
            for(auto it:g[i]){
                lli mini=min(i,it);
                lli maxi=max(i,it);
                if(pairs[{mini,maxi}]==-1){
                    pairs[{mini,maxi}]=mex;
                    mex++;
                } 
            }   
        }
    }
    
    fa(ht){
        lli vertex=it.second;
        lli parr=parent[it.second];
        if(vertex>parr) swap(vertex,parr);
        if (parr==-1) continue;
        if(pairs[{vertex,parr}]==-1){
            pairs[{vertex,parr}]=mex;
            mex++;
        } 
    }
    for (auto &e:edge_order) {
        cout<<pairs[e]<<endl;
    }
    return 0;
}