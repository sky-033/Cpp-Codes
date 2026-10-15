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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

lli fact[N+1], invfact[N+1];

lli modpow(lli a, lli b) {
    lli res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for(lli i = 1; i <= N; i++) fact[i] = fact[i-1] * i % M;
    invfact[N] = modpow(fact[N], M-2); // Fermat inverse
    for(lli i = N-1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % M;
}

lli nCr(lli n, lli r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % M * invfact[n-r] % M;
}

void solve(){
    lli n,k;
    cin>>n>>k;

    lli pow=bitlen(n)-1;
    lli ans=0;
    if(pow+1>k) ans++;
    ff(1,pow+1,1){
        lli mini=max(0LL,k-i+1);
        for(lli j=mini;j<i;j++){
            ans+=nCr(i-1,j);
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
    precompute();
    while(t--){
        solve();
    }
    return 0;
}