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
const lli N=701;
const lli M=1e9+7; 

vp movement={{1,0},{0,1},{-1,0},{0,-1}};
lli n,m;
bool valid(lli x,lli y){
    return x>0 && y>0 && x<=n && y<=m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        lli a[n+1][m+1];
        unordered_map<lli,vp> num;
        lli ct1=0,ct2=0;
        for(lli i=1;i<=n;i++){
            for(lli j=1;j<=m;j++){
                cin>>a[i][j];
                num[a[i][j]].push_back({i,j});
            }
        }
        fa(num){
            bool flag=false;
            for(auto val:it.second){
                lli x=val.first;
                lli y=val.second;
                for(auto move:movement){
                    lli x_c=x+move.first;
                    lli y_c=y+move.second;
                    if(valid(x_c,y_c) && a[x][y]==a[x_c][y_c]){
                        ct2++;
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag) ct1++;
        }
        if(ct2>0) cout<<2*(ct2-1) +ct1<<endl;
        else cout<<ct1-1<<endl;
    }
    return 0;
}