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
    vll a(n);
    set<lli> st,contain,main;
    f(i,n){
        cin>>a[i];
        main.insert(a[i]);
        contain.insert(a[i]);
    }
    sort(all(a));
    f(i,n){
        if(contain.find(a[i])==contain.end()) continue;
        st.insert(a[i]);
        for(lli j=a[i];j<=k;j+=a[i]){
            if(contain.find(j)!=contain.end()) contain.erase(j);
            if(main.find(j)==main.end()){
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<st.size()<<endl;
    fa(st) cout<<it<<" ";
    cout<<endl;
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