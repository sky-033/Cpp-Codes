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
const lli N=1e6+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif


vll lpf(N+1,0),hpf(N+1,0);    
vector<bool> isPrime(N+1,true); 

void sieve() {
    isPrime[0]=isPrime[1]=false;
    for(lli i=2;i<=N;++i) {
        if(lpf[i]==0){  
            lpf[i]=hpf[i]=i;
            for(lli j=2*i;j<=N;j+=i){
                hpf[j]=i;              
                if(lpf[j]==0) lpf[j]=i; 
                isPrime[j]=false;
            }
        }
    }
}

void solve(){
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    bool check=true;
    f(i,n-1){
        if(a[i]>a[i+1]){
            check=false;
            break;
        }
    }
    if(check){
        cout<<"Bob"<<endl;
        return;
    }
    lli maxi=-1;
    f(i,n){
        if(lpf[a[i]]!=hpf[a[i]]){
            cout<<"Alice"<<endl;
            return;
        }
        if(maxi>lpf[a[i]]){
            cout<<"Alice"<<endl;
            return;
        }
        maxi=max(maxi,hpf[a[i]]);
    }
    cout<<"Bob"<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}