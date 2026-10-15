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
    vll a(n);
    f(i,n) cin>>a[i];
    lli sum=accumulate(all(a),0LL);
    lli ct1=0;
    f(i,n){
        if(a[i]==1) ct1++;
    }
    lli ans=0,left=0;
    if(n-ct1>1){
        f(i,n){
            if(a[i]!=1){
                ans+=a[i];
                left+=(a[i]-2)/2;
            }
        }
        ans+=min(left,ct1);
    }
    else{
        f(i,n){
            if(a[i]!=1){
                ans+=a[i];
                left=a[i]/2;
            }
        }
        ans+=min(left,ct1);
    }
    if(ct1==n || sum<3){
        cout<<0<<endl;
        return;
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