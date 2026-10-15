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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vll mini(n+1,n+1);
        f(i,m){
            lli x,y;
            cin>>x>>y;
            if(x>y) swap(x,y);
            mini[x]=min(mini[x],y);
        }
        lli minii=n+1;
        for(lli i=n;i>0;i--){
            minii=min(minii,mini[i]);
            mini[i]=minii;
        }
        lli ct=n;
        ff(1,n+1,1){
            ct+=max(0LL,mini[i]-i-1);
        }
        cout<<ct<<endl;
    }
    return 0;
}