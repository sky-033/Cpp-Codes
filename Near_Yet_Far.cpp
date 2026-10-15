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
    lli n,k;
    cin>>n>>k;
    vll a(n);
    f(i,n) cin>>a[i];
    if(k==2){
        lli maxiE=0,miniE=1e18,maxiO=0,miniO=1e18;
        ff(0,n,2){
            maxiE=max(maxiE,a[i]);
            miniE=min(miniE,a[i]);
        }
        ff(1,n,2){
            maxiO=max(maxiO,a[i]);
            miniO=min(miniO,a[i]);
        }
        cout<<max(maxiO-miniO,maxiE-miniE)<<endl;
    }
    else{
        vp v;
        f(i,n){
            v.push_back({a[i],i+1});
        }
        sort(all(v));
        lli ans=0;
        lli f1=v[0].first,f2=v[1].first,f3=v[2].first,i1=v[0].second,i2=v[1].second,i3=v[2].second;
        for(lli i=n-1;i>=n-3;i--){
            lli val=v[i].first;
            lli idx=v[i].second;
            if(abs(idx-i1)>=2) ans=max(ans,val-f1);
            if(abs(idx-i2)>=2) ans=max(ans,val-f2);
            if(abs(idx-i3)>=2) ans=max(ans,val-f3);
        }
        cout<<ans<<endl;
    }
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