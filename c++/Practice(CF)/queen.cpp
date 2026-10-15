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
const lli N=1e5+10;
const lli M=1e9+7; 

vll c(N);
vll g[N];
vll parent(N);

void dfs(lli vertex,lli par=0){
    parent[vertex]=par;
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,root;
    cin>>n;
    ff(1,n+1,1){
        lli x,c1;
        cin>>x>>c1;
        c[i]=c1;
        if(x==-1){
            root=i;
            continue;
        }
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(root);
    vll ans;
    ff(1,n+1,1){
        if(c[i]==0) continue;
        bool flag=true;
        fa(g[i]){
            if(it!=parent[i] && c[it]==0){
                flag=false;
                break;
            }
        }
        if(flag) ans.push_back(i);
    }
    if(ans.size()==0) cout<<-1<<endl;
    else{
        fa(ans) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}