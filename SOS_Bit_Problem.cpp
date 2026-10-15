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
    lli n;
    cin>>n;
    vll x(n);
    vll sub(1<<20,0),super(1<<20,0);
    f(i,n){
        cin>>x[i];
        sub[x[i]]++;
        super[x[i]]++;
    }
    for(lli i=0;i<20;i++){
        for(lli mask=0;mask<(1<<20);mask++){
            if(mask&(1<<i)) sub[mask]+=sub[mask^(1<<i)];
        }
    }
    for(lli i=0;i<20;i++){
        for(lli mask=0;mask<(1<<20);mask++){
            if(!(mask&(1<<i))) super[mask]+=super[mask^(1<<i)];
        }
    }
    f(i,n) cout<<sub[x[i]]<<" "<<super[x[i]]<<" "<<n-sub[((1<<20)-1)^x[i]]<<endl;
    

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