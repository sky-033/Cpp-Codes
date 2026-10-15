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
vector<bool> vis(N);

bool dfs(lli vertex,lli parent){
    vis[vertex]=true;
    bool isLoopExists=false;
    for(auto child : g[vertex]){
        if(vis[child] && child==parent) continue;
        if(vis[child]) return true;
        isLoopExists|=dfs(child,vertex);  //dekho isse false aur true dono aayega par ek bhi true hogya toh OR operation se hamesa true hee rahega
    }
    return isLoopExists;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,e;
        cin>>n>>e;
        f(i,e){
            lli x,y;
            cin>>x>>y;
            g[x].push_back(y);
           // g[y].push_back(x);
        }
        bool isLoopExists=false;
        ff(1,n+1,1){                 // graph nhi forest diya hua hai bhai
            if(vis[i]) continue;
            isLoopExists=dfs(i,0);
            if(isLoopExists) break;
        }
        cout<<(isLoopExists? "YES" : "NO")<<endl;
    }
    return 0;
}