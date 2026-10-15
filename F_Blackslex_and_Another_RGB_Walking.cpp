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
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void first(){
    lli t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vll g[n+1];
        f(i,m){
            lli u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vll level(n+1,0),vis(n+1,0);
        vis[1]=1;         
        queue<lli> q;
        q.push(1);
        while(!q.empty()){
            lli cur_v=q.front();
            q.pop();
            for(auto child:g[cur_v]){
                if(vis[child]==0){
                    vis[child]=1;
                    q.push(child);
                    level[child]=level[cur_v]+1;
                }
            }
        }
        string ans="";
        ff(1,n+1,1){
            if(level[i]%3==0){
                ans+='r';
            }
            else if(level[i]%3==1){
                ans+='g';
            }
            else{
                ans+='b';
            }
        }
        cout<<ans<<endl; 
    }
}
void second(){
    lli t;
    cin>>t;
    while(t--){
        lli q;
        cin>>q;
        while(q--){
            lli n;
            cin>>n;
            string neigh;
            cin>>neigh;
            bool r=false,g=false,b=false;
            fa(neigh){
                if(it=='r') r=true;
                if(it=='g') g=true;
                if(it=='b') b=true;
            }
            char next=' ';
            if(r && g) next='g';      
            else if(g && b) next='b'; 
            else if(b && r) next='r'; 
            else{
                if(r) next='r';
                else if(b) next='b';
                else next='g';
            }
            ff(0,n,1){
                if(neigh[i]==next) {
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    if(s=="first"){
        first();
    }
    else{
        second();
    }
    return 0;
}