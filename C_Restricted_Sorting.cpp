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
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    bool check=true;
    f(i,n-1){
        if(a[i+1]<a[i]){
            check=false;
            break;
        }
    }
    lli mini=*min_element(all(a));
    lli maxi=*max_element(all(a));
    if(check){
        cout<<-1<<endl;
        return;
    }
    vll sorted_vec=a;
    sort(all(sorted_vec));
    lli ans=1e18;
    f(i,n){
        if(a[i]!=sorted_vec[i]){
            lli d1=abs(a[i]-mini);
            lli d2=abs(a[i]-maxi);
            ans=min(ans,max(d1,d2));
        }
    }
    cout<<ans<<endl;
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