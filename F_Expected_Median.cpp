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
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
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
    lli n,k,ct1=0;
    cin>>n>>k;
    vll a(n);
    f(i,n){
        cin>>a[i];
        if(a[i]==1) ct1++;
    }
    lli ct0=n-ct1;
    lli total=0;
    for(lli i=k/2 +1;i<=min(ct1,k);i++){
        total=(total+nCr(ct1,i)*nCr(ct0,k-i))%M;
    }
    cout<<total<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    precompute();
    while(t--){
        solve();
    }
    return 0;
}