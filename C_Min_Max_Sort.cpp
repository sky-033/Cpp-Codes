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

bool check(vll &p, lli n,lli mid){
    lli low=mid;
    lli high=n-mid+1;
    set<lli> st;
    f(i,n){
        if(p[i]>low && p[i]<high){
            auto it=st.upper_bound(p[i]);
            if(it==st.end()) st.insert(p[i]);
            else return false;
        }
    }
    return true;
}

void solve(){
    lli n;
    cin>>n;
    vll p(n);
    f(i,n) cin>>p[i];
    lli l=0,h=n;
    while(h-l>1){
        lli mid=(l+h)/2;
        if(check(p,n,mid)) h=mid;
        else l=mid+1;
    }
    if(check(p,n,l)) cout<<l<<endl;
    else cout<<h<<endl;
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