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
vector<vector<char>> grid;

lli dx[4]={1, -1, 0, 0};
lli dy[4]={0, 0, 1, -1};
char dir[4]={'D', 'U', 'R', 'L'};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

void solve(){
    lli xa,ya;
    queue<pair<lli,lli>> q,qa;
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    vvll distM(n,vll(m,1e9)),distA(n,vll(m,1e9));
    vector<vector<pair<lli,lli>>> parent(n,vp(m));
    vector<vector<char>> move(n,vector<char>(m));
    f(i,n){
        f(j,m){
            cin>>grid[i][j];
            if(grid[i][j]=='M'){
                q.push({i,j});
                distM[i][j]=0;
            }
            if(grid[i][j]=='A'){
                xa=i,ya=j;
                qa.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        lli x=node.first,y=node.second;
        f(i,4){
            lli x1=x+dx[i];
            lli y1=y+dy[i];
            if(isValid(x1,y1) && distM[x1][y1]==1e9){
                distM[x1][y1]=distM[x][y]+1;
                q.push({x1,y1});
            }
        }
    }

    distA[xa][ya]=0;

    if(xa==0 || xa==n-1 || ya==0 || ya==m-1){
        yes;
        cout<<0<<endl;
        return;
    }

    lli xe=-1,ye=-1;
    while(!qa.empty()){
        auto node=qa.front();
        qa.pop();
        lli x=node.first,y=node.second;
        f(i,4){
            lli x1=x+dx[i];
            lli y1=y+dy[i];
            if(isValid(x1,y1) && distA[x1][y1]==1e9 && distA[x][y]+1<distM[x1][y1]){
                distA[x1][y1]=distA[x][y]+1;
                qa.push({x1,y1});
                parent[x1][y1]={x,y};
                move[x1][y1]=dir[i];
                if(x1==0 || x1==n-1 || y1==0 || y1==m-1){
                    xe=x1,ye=y1;
                    break;
                }
            }
        }
        if(xe!=-1) break;
    }
    
    if(xe==-1){
        no;
        return;
    }

    string path;

    while(xa!=xe || ya!=ye){
        path.push_back(move[xe][ye]);
        auto p=parent[xe][ye];
        xe=p.first,ye=p.second;
    }
    reverse(all(path));

    yes;
    cout<<path.size()<<endl;
    cout<<path<<endl;
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