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
    lli n,q;
    cin>>n>>q;
    vll a(n);
    f(i,n) cin>>a[i];
    sort(all(a));
    set<lli> st;
    fa(a) st.insert(it);
    lli nn=st.size();
    vll times;

    f(i,n-1){
        if(a[i]!=a[i+1]){
            times.push_back(a[i+1]-a[i]);
        }
    }

    sort(all(times));
    lli m=times.size();
    vll prefix(m);
    if(m>0){
        prefix[0]=times[0];
        for(lli i=1;i<m;i++){
            prefix[i]=prefix[i-1]+times[i];
        }
    }
    //debug(times,prefix);
    while(q--){
        lli x;
        cin>>x;
        auto it=lower_bound(all(times),x);

        lli idx=it-times.begin();
        if(idx==m-1 && times[idx]==x){
            cout<<nn*x<<endl;
            continue;
        }
        lli ans=0;
        //debug(idx);
        if(idx!=0) ans+=prefix[idx-1];
        ans+=(nn-idx)*x;

       cout<<ans<<endl;

    }
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