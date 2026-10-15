#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=4005;
const lli M=1e9+7; 
string s;
vll g[N];
vp subtree(N);
void dfs(lli vertex,lli par){
    if(s[vertex-1]=='W') subtree[vertex].second++;   //update parent data with parent's current data
    else subtree[vertex].first++;
    for(auto child: g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree[vertex].second+=subtree[child].second;   //update parent data with child's data
        subtree[vertex].first+=subtree[child].first;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        ff(1,n+1,1){
            g[i].clear();
        }
        subtree = vp(N, {0, 0});
        vll a(n);
        f(i,n-1) cin>>a[i];
        cin>>s;
        ff(1,n,1){
            lli x=i+1;
            lli y=a[i-1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
        lli ct=0;
        ff(1,n+1,1){
            if(subtree[i].first==subtree[i].second) ct++;
        }
        cout<<ct<<endl;
    }
    return 0;
}