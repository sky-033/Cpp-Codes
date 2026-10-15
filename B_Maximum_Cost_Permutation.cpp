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
    lli n;
    cin>>n;
    set<lli> st;
    ff(1,n+1,1) st.insert(i);
    vll a(n);
    f(i,n) cin>>a[i];
    fa(a){
        if(it!=0) st.erase(it);
    }
    vll v;
    fa(st) v.push_back(it);
    reverse(all(v));
    lli indx=0;
    f(i,n){
        if(a[i]==0){
            a[i]=v[indx];
            indx++;
        }
    }
    lli l=-1,h=-1;
    f(i,n){
        if(i+1!=a[i]){
            l=i;
            break;
        }
    }
    for(lli i=n-1;i>=0;i--){
        if(i+1!=a[i]){
            h=i;
            break;
        }
    }
    // fa(a) cout<<it<<" ";
    if(h==l) cout<<0<<endl;
    else cout<<h-l+1<<endl;
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