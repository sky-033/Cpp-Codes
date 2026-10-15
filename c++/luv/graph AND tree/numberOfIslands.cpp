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
const lli N=301;
const lli M=1e9+7; 

void dfs(lli i,lli j, vvll &grid){
    lli n=grid.size();
    lli m=grid[0].size();
    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(grid[i][j]!=1) return;
    grid[i][j]=2;
    dfs(i-1,j,grid);
    dfs(i,j-1,grid);
    dfs(i+1,j,grid);
    dfs(i,j+1,grid);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vvll grid(n);
        f(i,n){
            grid[i].resize(m);
            g(j,m) cin>>grid[i][j];
        }
        lli ct=0;
        f(i,n){
            g(j,m){
                if(grid[i][j]!=1) continue;
                dfs(i,j,grid);
                ct++;
            }
        }
        cout<<ct<<endl;

    }
    return 0;
}