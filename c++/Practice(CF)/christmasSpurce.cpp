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
const lli N=1001;
const lli M=1e9+7; 

lli n;
vll g[N];
vll height(N);

void dfs(lli vertex,lli par=-1){
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    f(i,n-1){
        lli x;
        cin>>x;
        g[x].push_back(i+2);
        g[i+2].push_back(x);
    }
    dfs(1);
    bool flag=true;
    ff(1,n+1,1){
        if(height[i]!=0){
            lli ct=0;
            fa(g[i]){
                if(height[it]==0) ct++;
            }
            if(ct<3){
                flag=false;
                break;
            }
        }
    }
    cout<<(flag?"YES":"NO")<<endl;
    return 0;
}