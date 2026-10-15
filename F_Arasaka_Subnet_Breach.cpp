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
    lli n,k;
    cin>>n>>k;
    vll a(n);
    f(i,n) cin>>a[i];
    lli prod=1;

    fa(a) prod*=it;

    if(prod==2023){
        yes;
        f(i,k) cout<<1<<" ";
        cout<<endl;
    }
    else if(prod==17){
        yes;
        cout<<119<<" ";
        f(i,k-1) cout<<1<<" ";
        cout<<endl;
    }
    else if(prod==7){
        yes;
        cout<<289<<" ";
        f(i,k-1) cout<<1<<" ";
        cout<<endl;
    }
    else if(prod==289){
        yes;
        cout<<7<<" ";
        f(i,k-1) cout<<1<<" ";
        cout<<endl;
    }
    else if(prod==119){
        yes;
        cout<<17<<" ";
        f(i,k-1) cout<<1<<" ";
        cout<<endl;
    }
    else if(prod==1){
        yes;
        cout<<2023<<" ";
        f(i,k-1) cout<<1<<" ";
        cout<<endl;
    }
    else no;
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