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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
    vll a(n),b(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>b[i];
    lli ans=0;
    f(i,n){
        if(i==0){
            lli g=__gcd(a[i],a[i+1]);
            if(g!=a[i]){
                ans++;
            }
        }
        else if(i==n-1){
            lli g=__gcd(a[i],a[i-1]);
            if(g!=a[i]){
                ans++;
            }
        }
        else{
            lli g1=__gcd(a[i],a[i-1]);
            lli g2=__gcd(a[i],a[i+1]);

            lli val=(g1*g2)/__gcd(g1,g2);
            if(val<a[i]) ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}