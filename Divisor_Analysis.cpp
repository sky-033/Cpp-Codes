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

const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

lli num=1,sum1=1,prod=1;
lli N=1,cnt=1;
lli modpow(lli a, lli b) {
    lli res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

lli modinv(lli x){
    return modpow(x, M-2);
}

void number(lli x,lli k){
    num=(num*(k+1))%M;
}
void sum(lli x,lli k){
    lli numerator=(modpow(x,k+1)-1+M)%M;
    lli denom=modinv(x-1);
    lli val=(numerator*denom)%M;
    sum1=(sum1*val)%M;
}
void product(lli x, lli k){
    lli temp = prod;

    // raise current product to (k+1)
    prod = modpow(prod, k+1);

    // multiply contribution of current prime
    lli exponent = (k * (k+1) / 2) % (M-1);
    prod = (prod * modpow(modpow(x, exponent), cnt)) % M;

    // update divisor count
    cnt = (cnt * (k+1)) % (M-1);
}
void solve(){
    lli n;
    cin>>n;

    f(i,n){
        lli x,k;
        cin>>x>>k;
        number(x,k);
        sum(x,k);
        product(x,k);
    }
    //prod=modpow(N,d/2);
    cout<<num<<" "<<sum1<<" "<<prod<<endl;
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