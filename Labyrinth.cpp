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

lli n,m;
vector<vector<char>> g;
vector<vector<char>> v1;
vvll visited,visited1;
vp v={{1,0},{0,-1},{0,1},{-1,0}};
//vector<char> d={'U','L','R','D'};
vector<char> d={'D','L','R','U'};
lli ct;
void dfs(lli i,lli j){
    visited[i][j]=1;
    fa(v){
        lli i1=i+it.first;
        lli j1=j+it.second;
        if(i1>=0 && i1<n && j1>=0 && j1<m && (g[i1][j1]=='.' || g[i1][j1]=='A' || g[i1][j1]=='B')  && !visited[i1][j1]){
            dfs(i1,j1);
        }
    }
}

void dfs1(lli i,lli j){
    visited1[i][j]=1;
    v1[ct].push_back(g[i][j]);
    fa(v){
        lli i1=i+it.first;
        lli j1=j+it.second;
        if(i1>=0 && i1<n && j1>=0 && j1<m && (g[i1][j1]=='.' || g[i1][j1]=='A' || g[i1][j1]=='B')  && !visited1[i1][j1]){
            dfs1(i1,j1);
        }
    }
   // ct++;
}

void solve(){
    cin>>n>>m;
    g.resize(n,vector<char>(m));
    visited.resize(n,vll(m));
    visited1.resize(n,vll(m));
    lli xa,ya,xb,yb;
    f(i,n){
        f(j,m){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                xa=i,ya=j;
            }
            if(g[i][j]=='B'){
                xb=i,yb=j;
            }
            visited[i][j]=0;
            visited1[i][j]=0;
            if(g[i][j]=='#'){
                visited[i][j]=1;
                visited1[i][j]=1;
            }
        }
    }
    lli ans=0;
    

    f(i,n){
        f(j,m){
            if(!visited[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    }
    ct=0;
    v1.resize(ans);
    f(i,n){
        f(j,m){
            if(!visited1[i][j]){
                //ans++;
                dfs1(i,j);
                ct++;
            }
        }
    }
    //debug(g);
    //debug(visited);
    //cout<<ans<<endl;
    debug(v1);
    lli c=-1;
    f(i,ans){
        fa(v1[i]){
            if(it=='A'){
                c=i;
                break;
            }
        }
    }
    bool flag=false;
    fa(v1[c]){
        if(it=='B'){
            flag=true;
            break;
            
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        string s;
        queue<pair<lli,lli>> q;
        vvll vis(n,vll(m,0));
        vis[xa][ya]=1;
        q.push({xa,ya});
        vector<vector<pair<lli,lli>>> parent(n,vp(m));
        vector<vector<char>> move(n,vector<char>(m));
        while(!q.empty()){
            auto itt=q.front();
            q.pop();
            lli x=itt.first,y=itt.second;
            f(i,4){
                lli x_1=x+v[i].first,y_1=y+v[i].second;
                if(x_1>=0 && x_1<n && y_1>=0 && y_1<m &&(g[x_1][y_1]=='.' || g[x_1][y_1]=='A' || g[x_1][y_1]=='B')  && !vis[x_1][y_1]){
                    q.push({x_1,y_1});
                    vis[x_1][y_1]=1;
                    parent[x_1][y_1]={x,y};
                    move[x_1][y_1]=d[i];
                }
            }
        }
        while(xa!=xb || ya!=yb){
            s.push_back(move[xb][yb]);
            auto p=parent[xb][yb];
            xb=p.first;
            yb=p.second;
        }
        reverse(all(s));
        cout<<s.size()<<endl;
        cout<<s<<endl;
    }
    else no;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}