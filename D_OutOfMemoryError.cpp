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
    lli n,m,h;
    cin>>n>>m>>h;
    vll a(n);
    f(i,n) cin>>a[i];
    vll temp(n,0);
    vll updated(n,0);
    lli prev=0;
    f(i,m){
        lli b,c;
        cin>>b>>c;
        b--;
        if(updated[b]>prev){
            temp[b]+=c;
        }
        else{
            temp[b]=a[b]+c;
        }
        lli val=temp[b];
        updated[b]=i+1;
        if(val>h){
            prev=i+1;
        }
    }
    // debug(temp);
    // debug(updated);
    // debug(prev);
    f(i,n){
        if(updated[i]<=prev) cout<<a[i]<<" ";
        else cout<<temp[i]<<" ";
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