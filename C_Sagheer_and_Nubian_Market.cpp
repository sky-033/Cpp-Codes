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
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n,S;
    cin>>n>>S;
    vll a(n+1);
    f(i,n) cin>>a[i+1];
    lli l1=1,h1=n,T=0,K=0;
    while(l1<=h1){
        lli mid1=(l1+h1)/2;
        vll temp(n+1);
        ff(1,n+1,1) temp[i]=a[i]+mid1*i;
        sort(all(temp));
        lli cost=0;
        ff(1,mid1+1,1) cost+=temp[i];
        if(cost<=S){
            T=cost;
            K=mid1;
            l1=mid1+1;
        }
        else h1=mid1-1;

    }
    cout<<K<<" "<<T<<endl;
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