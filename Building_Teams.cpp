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
lli n,m;
vvll g;

vll color;
 
bool check(lli st){
    queue<lli> q;
    q.push(st);
    color[st]=0;
    while(!q.empty()){
        lli node=q.front();
        q.pop();
        fa(g[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]) return false;
        }
    }
    return true;
}
bool isBipartite(lli n){
    ff(1,n+1,1){
        if(color[i]==-1){
            if(check(i)==false){
                return false;
            }
        }
    }
    return true;
}
 
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    color.resize(n+1,-1);
    f(i,m){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ff(1,n+1,1){
        if(color[i]==-1){
            if(!isBipartite(i)){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    ff(1,n+1,1) cout<<color[i]+1<<" ";
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