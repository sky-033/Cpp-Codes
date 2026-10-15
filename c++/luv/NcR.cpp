#include <bits/stdc++.h>
using namespace std;
#define lli long long
const int M = 1e9+7;
const int N = 1e6; // Adjust as needed

lli fact[N+1], invfact[N+1];

lli modpow(int a, int b) {
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

lli nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % M * invfact[n-r] % M;
}

int32_t main() {
    precompute();
    cout << nCr(1000000, 500000) << "\n"; // Example
}
