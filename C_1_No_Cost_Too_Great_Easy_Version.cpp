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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define endl '\n'
const lli N=2e5+1;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// set<lli> getFactors(lli n) {
//     set<lli> factors;
//     for(lli i=2;i*i<=n;i++) {
//         if(n%i==0){
//             factors.insert(i);
//             while(n%i==0) n/=i;
//         }
//     }
//     if(n>1) factors.insert(n);
//     return factors;
// }

vector<lli> spf(N + 1);


void precompute_sieve() {
    iota(spf.begin(), spf.end(), 0); // Fills spf with 0, 1, 2, ...
    for (lli i = 2; i * i <= N; ++i) {
        if (spf[i] == i) { // i is prime
            for (lli j = i * i; j <= N; j += i) {
                if (spf[j] == j) { // Only set if not set by a smaller prime
                    spf[j] = i;
                }
            }
        }
    }
}

// Get all unique prime factors of k
set<lli> getFactors(lli k) {
    set<lli> factors;
    while (k > 1) {
        lli p = spf[k];
        factors.insert(p);
        while (k % p == 0) {
            k /= p;
        }
    }
    return factors;
}

void solve(){
    lli n;
    cin>>n;
    vll a(n),b(n);
    f(i,n){
        cin>>a[i];
    }
    f(i,n) cin>>b[i]; 
    set<lli> factors;
    f(i,n){
        set<lli> f=getFactors(a[i]);
        fa(f){
            if(factors.find(it)!=factors.end()){
                cout<<0<<endl;
                return;
            }
        }
        factors.insert(all(f));
    }
    f(i,n){
        lli val=a[i]+1;
        set<lli> f=getFactors(val);
        fa(f){
            if(factors.find(it)!=factors.end()){
                cout<<1<<endl;
                return;
            }
        }
    }
    cout<<2<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    precompute_sieve();
    while(t--){
        solve();
    }
    return 0;
}