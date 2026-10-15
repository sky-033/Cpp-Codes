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
vll subtree(N);

void dfs(lli vertex,lli par=-1){
    subtree[vertex]++;
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree[vertex]+=subtree[child];
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
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool flag=true;
    if(n&1) flag=false;
    dfs(1);
    lli ct=0;
    ff(1,n+1,1){
        if(subtree[i]%2==0) ct++;
    }
    if(flag) cout<<ct-1<<endl;
    else cout<<-1<<endl;
    return 0;
}