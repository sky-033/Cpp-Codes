// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define g(j,n) for(lli j=0;j<n;j++)
// #define h(k,n) for(lli k=0;k<n;k++)
// #define rf(i,n) for(lli i=n-1;i>=0;i--)
// #define ff(a,b,c) for(lli i=a;i<b;i+=c)
// #define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
// #define fa(v) for (auto &it : v) 
// #define all(x) (x).begin(), (x).end()
// #define sor(x) sort(all(x))
// #define setbits(x) __builtin_popcountll(x)
// #define bitlen(x) 64-__builtin_clzll(x)
// const lli N=1e5+10;
// const lli M=1e9+7; 
// lli n,m;

// vll g[N];
// vll vis(N);

// lli dfs(lli vertex,vll &c){
//     lli ans=1e9;
//     ans=min(ans,c[vertex]);
//     vis[vertex]=1;
//     for(auto child:g[vertex]){
//         if(vis[child]) continue;
//         // vis[child]=1;
//         ans=min(ans,dfs(child,c));
//     }
//     return ans;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin>>n>>m;
//     vll c(n+1);
//     ff(1,n+1,1) cin>>c[i];
//     f(i,m){
//         lli u,v;
//         cin>>u>>v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     lli cost=0;
//     ff(1,n+1,1){
//         if(vis[i]) continue;
//         lli ans=1e9;
//         cost+=dfs(i,c);
//     }
//     cout<<cost<<endl;
//     return 0;
// }



// Alternate Method

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
const lli N=1e5+10;
const lli M=1e9+7; 
lli n,m;
vll g[N];
vll vis(N);
vvll con_comp;
vll current_cc;
void dfs(lli vertex){
    vis[vertex]=1;
    current_cc.push_back(vertex);
    for(auto child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    vll c(n+1);
    ff(1,n+1,1) cin>>c[i];
    f(i,m){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ff(1,n+1,1){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        con_comp.push_back(current_cc);
    }
    lli ans=0;
    fa(con_comp){
        lli val=1e9;
        for(auto itt:it){
            val=min(val,c[itt]);
        }
        ans+=val;
    }
    cout<<ans<<endl;
    return 0;
}