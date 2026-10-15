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

void solve(){
    lli n,k;
    cin>>n>>k;
    vll q(n),r(n);
    f(i,n) cin>>q[i];
    f(i,n) cin>>r[i];
    sort(all(q));
    sort(all(r));
    multiset<lli> rr;
    f(i,n) rr.insert(r[i]);
    lli ans=0;
    f(i,n){
        //x=qy+r (y>=r+1) -->x<=q(r+1)+r<=k --> r<=(k-q)/(q+1)
        lli r_thres=(k-q[i])/(q[i]+1);
        auto it=rr.upper_bound(r_thres);
        if(it==rr.begin()) continue;
        it--;
        rr.erase(it);
        ans++;
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}