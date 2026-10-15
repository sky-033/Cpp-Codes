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
vll val(N);
vll subtree_sum(N);
void dfs(lli vertex,lli par=0){
    subtree_sum[vertex]+=val[vertex];
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
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
        f(i,n-1){
            lli x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ff(1,n+1,1){
            lli x;
            cin>>x;
            val[i]=x;
        }
        dfs(1);
        lli ans=0;
        ff(2,n+1,1){
            lli val1=subtree_sum[i];
            lli val2=subtree_sum[1]-val1;
            ans=max(ans,(val1*val2)%M);
        }
        cout<<ans<<endl;
    }
    return 0;
}