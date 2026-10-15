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

void solve(){
    lli n,m;
    cin>>n>>m;
    vll a(n),b(m);
    f(i,n) cin>>a[i];
    f(i,m) cin>>b[i];
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    vll freq(n+m+1,0);
    fa(a){
        lli val=it;
        for(lli j=val;j<=(n+m);j+=val) freq[j]++;
    }
    lli alice=0,bob=0,both=0;
    n=a.size();
    fa(b){
        if(freq[it]==n) alice++;
        else if(freq[it]==0) bob++;
        else both++;
    }
    if(both%2==0) cout<<(alice>bob?"Alice":"Bob")<<endl;
    else cout<<(alice>=bob?"Alice":"Bob")<<endl;
    
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