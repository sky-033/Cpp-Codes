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
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

vll g[N];
vll subtree(N,0);

void dfs(lli vertex,lli par){
    subtree[vertex]=1;
    for(auto child : g[vertex]){
        if(par==child) continue;
        dfs(child,vertex);
        subtree[vertex]+=subtree[child];
    }
}
void solve(){
    lli n;
    cin>>n;
    lli node=2;
    f(i,n-1){
        lli x;
        cin>>x;
        g[x].push_back(node);
        g[node].push_back(x);
        node++;
    }
    dfs(1,0);
    ff(1,n+1,1) cout<<subtree[i]-1<<" ";
    cout<<endl;

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