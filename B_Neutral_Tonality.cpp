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
    lli n,m;
    cin>>n>>m;
    vll a(n),b(m),c(n+m);
    f(i,n) cin>>a[i];
    map<lli,lli> mp;
    f(i,m){
        cin>>b[i];
        mp[b[i]]++;
    }

    sort(all(b));
    lli j=0;
    f(i,n){
        lli val=a[i];
        c[j++]=val;
        while(mp[val]>0){
            c[j++]=val;
            mp[val]--;
        }
    }
    vll left;
    fa(mp){
        f(i,it.second) left.push_back(it.first);
    }
    if(left.size()==0){
        f(i,n+m) cout<<c[i]<<" ";
        cout<<endl;
        return;
    }
    reverse(all(left));
    vll v;
    fa(c){
        if(it!=0) v.push_back(it);
    }
    lli i=0;
    j=0;

    while(i<v.size() && j<left.size()){
        lli val1=v[i],val2=left[j];
        if(val1>val2){
            cout<<val1<<" ";
            i++;
        }
        else{
            cout<<val2<<" ";
            j++;
        }
    }
    for(lli k=i;k<v.size();k++) cout<<v[k]<<" ";
    for(lli k=j;k<left.size();k++) cout<<left[k]<<" ";
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