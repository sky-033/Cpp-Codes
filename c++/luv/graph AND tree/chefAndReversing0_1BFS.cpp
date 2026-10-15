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
const lli N=1e5+10;
const lli INF=1e9+7; 

vp g[N];
vll level(N,INF);

lli bfs(lli n){
    deque<lli> q;
    q.push_back(1);
    level[1]=0;
    while(!q.empty()){
        lli cur_v=q.front();
        q.pop_front();
        for(auto &child:g[cur_v]){
            lli child_v=child.first;
            lli wt=child.second;
            if(level[cur_v]+wt<level[child_v]){  //2 times maximum for each node...so does not affect TC
                level[child_v]=level[cur_v]+wt;
                if(wt==0) q.push_front(child_v);
                else q.push_back(child_v);
            }
        }
    }
    return (level[n]==INF? -1 : level[n]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    f(i,m){
        lli x,y;
        cin>>x>>y;
        if(x==y) continue;             //to avoid self loops
        g[x].push_back({y,0});         
        g[y].push_back({x,1});
    }
    cout<<bfs(n)<<endl;
    return 0;
}