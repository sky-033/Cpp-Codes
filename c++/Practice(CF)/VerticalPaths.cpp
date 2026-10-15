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

lli n;
vll g[N];
vll par(N);
vll height(N);
vll vis(N);

void dfs(lli vertex,lli parent=-1){
    for(auto child:g[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
}

vll path(lli vertex){
    vll ans;
    while(vertex!=-1){
        if(vis[vertex]){
            vertex=par[vertex];
        }
        else{
            ans.push_back(vertex);
            vis[vertex]=1;
            vertex=par[vertex];
        }    
    }
    reverse(all(ans));
    return ans;
}

void reset(){
    ff(1,n+1,1){
        g[i].clear();
        vis[i]=0;
        par[i]=0;
        height[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli root;
        cin>>n;
        reset();
        f(i,n){
            lli x;
            cin>>x;
            par[i+1]=x;
            if(i+1==x){
                root=i+1;
                par[i+1]=-1;
                continue;
            }
            g[i+1].push_back(x);
            g[x].push_back(i+1);
        }
        dfs(root);
        vvll anss;
        ff(1,n+1,1){
            if(height[i]==0){
                vll pathway=path(i);
                anss.push_back(pathway);
            }
        }
        cout<<anss.size()<<endl;
        fa(anss){
            cout<<it.size()<<endl;
            for(auto itt:it) cout<<itt<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}