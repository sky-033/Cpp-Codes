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
    set<lli> st;
    f(i,n){
        cin>>a[i];
        st.insert(i+1);
    }
    vll ans(n+1,0);
    f(i,n){
        lli val=a[i];
        auto it=st.upper_bound(val);
        if(it!=st.end()){
            ans[*it]=a[i];
            st.erase(it);
        }
        else{
            ans[*st.begin()]=a[i];
            st.erase(st.begin());
        }
    }
    ff(1,n+1,1) cout<<ans[i]<<" ";
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