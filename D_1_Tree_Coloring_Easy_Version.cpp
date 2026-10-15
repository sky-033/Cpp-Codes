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

void solve(){
    lli n;
    cin>>n;
    vll g[n+1];
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<lli> q;
    q.push(1);
    vll dist(n+1,0);
    dist[1]=1;
    vll vis(n+1,0);
    vis[1]=1;
    while(!q.empty()){
        lli cur_v=q.front();
        q.pop();
        for(auto child:g[cur_v]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
                dist[child]=dist[cur_v]+1;
            }
        }
    }
    map<lli,lli> mp;
    ff(1,n+1,1){
        lli d=dist[i];
        mp[d]++;
    }
    lli ans=0;
    fa(mp) ans=max(ans,it.second);
    // debug(ans);
    lli val=g[1].size();
    ans=max(ans,val+1LL);
    ff(2,n+1,1){
        val=g[i].size();
        ans=max(ans,val);
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}