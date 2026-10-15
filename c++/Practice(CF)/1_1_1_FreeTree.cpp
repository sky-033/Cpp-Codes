//OPTIMISE??????

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

vector<pair<lli,lli>> g[N];

void dfs(lli v,lli parent,vll &c,lli &cost){
    for(auto child:g[v]){
        if(child.first==parent) continue;
        if(c[child.first]!=c[v]) cost+=child.second;
        dfs(child.first,v,c,cost);
    }
}

void reset(lli n){
    ff(1,n+1,1){
        g[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,q;
        cin>>n>>q;
        reset(n);
        vll c(n+1);
        ff(1,n+1,1) cin>>c[i];
        f(i,n-1){
            lli u,v,wt;
            cin>>u>>v>>wt;
            g[u].push_back({v,wt});
            g[v].push_back({u,wt});
        }
        lli cost=0;
        dfs(1,0,c,cost);
        // cout<<cost<<endl;
        f(i,q){
            lli v,x;
            cin>>v>>x;
            if(x==c[v]) cout<<cost<<endl;
            else{
                for(auto child:g[v]){
                    if(c[child.first]!=c[v]) cost-=child.second;
                }
                c[v]=x;
                for(auto child:g[v]){
                    if(c[child.first]!=c[v]) cost+=child.second;
                }
                cout<<cost<<endl;
            } 
        }
    }
    return 0;
}