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
vector<vector<char>> g;
vvll visited;
vp v={{1,0},{0,-1},{0,1},{-1,0}};

void dfs(lli i,lli j){
    visited[i][j]=1;
    fa(v){
        lli i1=i+it.first;
        lli j1=j+it.second;
        if(i1>=0 && i1<n && j1>=0 && j1<m && g[i1][j1]=='.'  && !visited[i1][j1]){
            dfs(i1,j1);
        }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n,vector<char>(m));
    visited.resize(n,vll(m));
    f(i,n){
        f(j,m){
            cin>>g[i][j];
            visited[i][j]=0;
            if(g[i][j]=='#') visited[i][j]=1;
        }
    }
    lli ans=0;
    

    f(i,n){
        f(j,m){
            if(!visited[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    //debug(g);
    //debug(visited);
    cout<<ans<<endl;
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