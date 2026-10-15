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
bool check(vll &k,lli n,lli mid,lli t){
    lli T=0;
    f(i,n) T+=mid/k[i];
    T-=t;
    return T>=0;
}
void solve(){
    lli n,t;
    cin>>n>>t;
    vll k(n);
    f(i,n) cin>>k[i];
    lli mini=*min_element(all(k));
    lli l=1,h=mini*t,mid;
    while(h-l>1){
        mid=l+(h-l)/2;
        if(check(k,n,mid,t)) h=mid;
        else l=mid+1;
    }
    if(check(k,n,l,t)) cout<<l<<endl;
    else cout<<h<<endl;
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