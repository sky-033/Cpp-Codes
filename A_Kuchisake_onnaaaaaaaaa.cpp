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
    lli n,q;
    cin>>n>>q;
    vll a(n),b(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>b[i];

    f(i,n){
        if(a[i]<b[i]) swap(a[i],b[i]);
    }

    lli maxi=a[n-1];

    for(lli i=n-1;i>=0;i--){
        maxi=max(a[i],maxi);
        a[i]=maxi;
    }

    vll prefix(n,0);

    prefix[0]=a[0];

    ff(1,n,1) prefix[i]=prefix[i-1]+a[i];

    while(q--){
        lli l,r;
        cin>>l>>r;
        l--,r--;

        if(l==0) cout<<prefix[r]<<" ";
        else cout<<prefix[r]-prefix[l-1]<<" ";
    }
    cout<<endl;
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