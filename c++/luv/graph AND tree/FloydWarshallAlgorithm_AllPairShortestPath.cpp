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

const lli N=501;
const lli INF=1e9+7; 

lli d[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    f(i,N){
        g(j,N){
            if(i==j) d[i][j]=0;
            else d[i][j]=INF;
        }
    }
    lli n,m;
    cin>>n>>m;
    f(i,m){
        lli x,y,wt;
        cin>>x>>y>>wt;
        d[x][y]=wt;
    }
    for(lli k=1;k<=n;k++){
        for(lli i=1;i<=n;i++){
            for(lli j=1;j<=n;j++){
                if(d[i][k]!=INF && d[k][j]!=INF){
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }
    for(lli i=1;i<=n;i++){
            for(lli j=1;j<=n;j++){
                if(d[i][j]==INF) cout<<"I"<<" ";
                else cout<<d[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}