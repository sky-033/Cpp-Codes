#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=7e5+10;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif


vll g[N];
vll color(N,-1);
lli n,m;
pair<lli,lli> check(lli st){
    queue<lli> q;
    q.push(st);
    color[st]=0;
    lli c0=1,c1=0;
    while(!q.empty()){
        lli node=q.front();
        q.pop();
        fa(g[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                if(it<=n){
                    if(color[it]==1) c1++;
                    else c0++;
                }
                q.push(it);
            }
            else if(color[it]==color[node]) return {-1,-1};
        }
    }
    return {c0,c1};
}


 
void reset(lli n){
    ff(1,n+1,1){
        color[i]=-1;
        g[i].clear();
    }
 
}

void solve(){
    cin>>n>>m;
    reset(n+m);
    lli fake=n+1;
    f(i,m){
        lli u,v;
        string s;
        cin>>u>>v>>s;
        if(s=="imposter"){
            g[u].push_back(v);
            g[v].push_back(u);
        }
        else{
            g[u].push_back(fake);
            g[fake].push_back(u);
            g[v].push_back(fake);
            g[fake].push_back(v);
            fake++;
        }
    }

    

    lli ans=0;
    ff(1,n+1,1){
        if(color[i]==-1){
            auto [c0,c1]=check(i);

            if(c0==-1){
                cout<<-1<<endl;
                return;
            }

            ans+=max(c0,c1);
        }
    }
    cout<<ans<<endl;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}