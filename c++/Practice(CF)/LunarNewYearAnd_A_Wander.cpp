#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vpw vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
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

vll g[N];
vll vis(N);
void bfs(lli source,vll &ans){
    vis[source]=1;
    set<lli> st;
    st.insert(source);
    while(st.size()>0){
        lli node=*st.begin();
        st.erase(st.begin());
        ans.push_back(node);
        // if(vis[node]) continue;
        vis[node]=1;
        for(auto child:g[node]){
            if(vis[child]==0){
                st.insert(child);
                vis[child]=1;
            }   
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    vll ans;
    f(i,m){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1,ans);
    fa(ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}