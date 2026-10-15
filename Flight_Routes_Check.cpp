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
    lli n,m;
    cin>>n>>m;
    vvll g(n+1),g1(n+1);
    f(i,m){
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g1[b].push_back(a);
    }

    queue<lli> q,q1;
    vll visited(n+1,0),visited1(n+1,0);
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        lli node=q.front();
        q.pop();
        visited[node]=1;
        fa(g[node]){
            if(visited[it]) continue;
            visited[it]=1;
            q.push(it); 
        }
    }

    ff(1,n+1,1){
        if(!visited[i]){
            no;
            cout<<1<<" "<<i<<endl;
            return;
        }
    }

    q1.push(1);
    visited1[1]=1;
    while(!q1.empty()){
        lli node=q1.front();
        q1.pop();
        visited1[node]=1;
        fa(g1[node]){
            if(visited1[it]) continue;
            visited1[it]=1;
            q1.push(it); 
        }
    }

    ff(1,n+1,1){
        if(!visited1[i]){
            no;
            cout<<i<<" "<<1<<endl;
            return;
        }
    }

    yes;
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