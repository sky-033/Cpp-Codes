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
const lli N=2e6+10;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
   
vector<bool> isPrime(N+1,true); 

vector<lli> primes;
void sieve() {
    isPrime[0]=isPrime[1]=false;
    for(lli i=2;i<=N;++i) {
        if(isPrime[i]){  
            for(lli j=2*i;j<=N;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(isPrime[i]) primes.push_back(i);
    }
}
void solve(){
    lli n;
    cin>>n;

    // if(primes.size()<n){
    //     cout<<-1<<endl;
    //     return;
    // }
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    if(n==2) cout<<23<<endl;
    else{
            f(i,n-2) cout<<4;
            cout<<77;
    
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    //sieve();
    while(t--){
        solve();
    }
    return 0;
}