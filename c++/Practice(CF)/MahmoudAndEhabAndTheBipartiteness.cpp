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
const lli N=2e5+10;
const lli M=1e9+7; 

vll g[N];
vll vis(N);
vll level(N);
void bfs(lli source){
    vis[source]=1;
    queue<lli> q;
    q.push(source);
    while(!q.empty()){
        lli cur_v=q.front();
        q.pop();
        for(auto child:g[cur_v]){
            if(vis[child]==0){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    f(i,n-1){
        lli u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<lli> g1,g2;
    bfs(1);
    ff(1,n+1,1){
        if(level[i]%2==0) g1.insert(i);
        else g2.insert(i);
    }
    lli ans=0;
    fa(g1){
        ans+=(g2.size()-g[it].size());  
    }
    cout<<ans<<endl;
    return 0;
}