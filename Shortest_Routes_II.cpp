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
const lli N=501;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

lli d[N][N];

void solve(){
    lli n,m,q;
    cin>>n>>m>>q;

    ff(1,n+1,1){
        for(lli j=1;j<=n;j++){
            if(i==j) d[i][j]=0;
            else d[i][j]=1e17;
        }
    }
    f(i,m){
        lli a,b,wt;
        cin>>a>>b>>wt;
        d[a][b]=min(d[a][b],wt);
        d[b][a]=min(d[a][b],wt);
    }

    for(lli k=1;k<=n;k++){
        for(lli i=1;i<=n;i++){
            for(lli j=1;j<=n;j++){
                if(d[i][k]!=1e17 && d[k][j]!=1e17){
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }

    while(q--){
        lli a,b;
        cin>>a>>b;
        if(d[a][b]==1e17) cout<<-1<<endl;
        else cout<<d[a][b]<<endl;
    }
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