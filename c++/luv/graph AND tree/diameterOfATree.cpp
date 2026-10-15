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
const lli N=2e5+10;
const lli M=1e9+7; 

vll g[N];
vll depth(N);

void dfs(lli vertex,lli par=-1){
    for(auto child:g[vertex]){
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    f(i,n-1){
        lli x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    lli max_depth=-1,max_depth_node;
    ff(1,n+1,1){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_depth_node=i;
        }
        depth[i]=0;
    }
    lli diameter=-1;
    dfs(max_depth_node);
    ff(1,n+1,1){
        diameter=max(diameter,depth[i]);
    }
    cout<<diameter<<endl;
    return 0;
}