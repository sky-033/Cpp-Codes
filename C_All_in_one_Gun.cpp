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
    lli n,h,k;
    cin>>n>>h>>k;
    vll a(n);
    f(i,n) cin>>a[i];
    lli sum=accumulate(all(a),0LL);
    lli ans=0;
    if(h>=sum){
        ans+=n*(h/sum)+(h/sum)*k;
    }
    h=h-h/sum*sum;
    if(h==0){
        cout<<ans-k<<endl;
        return;
    }
    lli more=1e18;
    lli ss=0;
    vll suffix(n);
    suffix[n-1]=a[n-1];
    for(lli i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],a[i]);
    }
    lli mini=a[0];
    // debug(suffix);
    f(i,n){
        ss+=a[i];
        mini=min(mini,a[i]);
        if(i!=n-1){
            if(mini<suffix[i+1]){
                lli val=ss-mini+suffix[i+1];
                if(val>=h){
                    more=min(more,i+1);
                }
            }
            else if(ss>=h) more=min(more,i+1);
        }
        else more=min(n,more);
    }
    // debug(more);
    // cout<<endl;
    cout<<more+ans<<endl;
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