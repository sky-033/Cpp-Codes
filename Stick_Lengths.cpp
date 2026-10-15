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

lli value(lli n,vll &a,lli x){
    lli ans=0;
    f(i,n) ans+=abs(a[i]-x);
    return ans;
}
void solve(){
    lli n;
    cin>>n;
    vll a(n);
    lli mini=1e9,maxi=-1e9;
    f(i,n){
        cin>>a[i];
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);
    }
    lli l=mini,h=maxi,mid1,mid2;
    while(h-l>2){
        mid1=l+(h-l)/3;
        mid2=h-(h-l)/2;
        lli val1=value(n,a,mid1),val2=value(n,a,mid2);
        if(val1<val2) h=mid2;
        else l=mid1;
    }

    lli ans=1e18;
    for(lli i=l;i<=h;i++){
        ans=min(ans,value(n,a,i));
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}