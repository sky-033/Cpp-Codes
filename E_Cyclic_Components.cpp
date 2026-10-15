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
#define sor(x) sort(all(x))
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
vector<bool> vis(N);
vvll cc;
vll current_cc;
void dfs(lli vertex){
    current_cc.push_back(vertex);
    vis[vertex]=true;
    for(auto child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}

void solve(){
    lli n,m;
    cin>>n>>m;
    f(i,m){
        lli x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ff(1,n+1,1){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }
    lli ct=0;
    fa(cc){
        bool flag=true;
        for(auto e:it){
            if(g[e].size()!=2){
                flag=false;
                break;
            }
        }
        if(flag) ct++;
    }
    cout<<ct<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t=1;
    while(t--){
        solve();
    }
    return 0;
}