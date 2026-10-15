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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

map<pair<lli,lli>,lli> vi;
vll g[N];
lli dp[N];
void dfs(lli vertex,lli parent=-1){
    for(auto &child:g[vertex]){
        if(child==parent) continue;
        if(vi[{parent,vertex}]<vi[{vertex,child}]) dp[child]=dp[vertex];
        else dp[child]=dp[vertex]+1;
        dfs(child,vertex);
    }
}
void reset(lli n){
    vi.clear(); 
    ff(1,n+1,1){
        g[i].clear();
        dp[i]=0;
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
        reset(n);
        f(i,n-1){
            lli u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            vi[{u,v}]=i+1;
            vi[{v,u}]=i+1;
        }
        vi[{-1,1}]=0;
        dp[1]=1;
        dfs(1);
        lli maxi=0;
        ff(1,n+1,1) maxi=max(maxi,dp[i]);
        cout<<maxi<<endl;
    }
    return 0;
}