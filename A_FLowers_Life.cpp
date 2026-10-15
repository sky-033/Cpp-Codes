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
    lli n;
    cin>>n;
    vll a(n);
    f(i,n ) cin>>a[i];
    lli ht=1;
    for(int i=0;i<n;i++){
        if(i==0){
            if(a[i]==1) ht++;
            continue;
        }
        if(a[i]==1){
            if(a[i-1]==1) ht+=5;
            else ht+=1;
        }
    }
    bool flag=false;
    for(int i=1;i<n;i++){
        if(a[i]==0 && a[i-1]==0){
            flag=true;
            break;
        }
    }
    if(flag) cout<<-1<<endl;
    else cout<<ht<<endl;
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