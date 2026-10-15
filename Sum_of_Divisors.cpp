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

lli sum_l_r(lli l,lli r){
    lli t1=(l+r)%M;
    lli t2=(r-l+1)%M;
    return (((t1*t2)%M)*(M+1)/2)%M;
}

void solve(){
    lli n;
    cin>>n;
    lli l=1;
    lli sum=0;
    while(l<=n){
        lli times=n/l;
        lli r=n/times;
        if(r>n) r=n;
        sum=(sum+((times%M)*sum_l_r(l,r))%M)%M;
        l=r+1;
    }
    cout<<sum<<endl;
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