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
    lli n,m,k;
    cin>>n>>m>>k;
    vll a(n),b(m);
    f(i,n) cin>>a[i];
    f(i,m) cin>>b[i];
    sort(all(b));
    string s;
    cin>>s;
    map<lli,lli> mp;
    lli cur=0;
    f(i,k){
        char t=s[i];
        if(t=='L') cur--;
        else cur++;
        if(mp.find(cur)==mp.end()){
            mp[cur]=i+1;
        }
    }
    map<lli,lli> death;
    f(i,n) death[a[i]]=1e18;
    f(i,n){
        lli time1=1e18,time2=1e18;
        auto left=lower_bound(all(b),a[i]);
        if(left!=b.begin()){
            left--;
            lli leftVal=*left;
            if(mp.find(leftVal-a[i])!=mp.end()) death[a[i]]=mp[leftVal-a[i]];
        }
        auto right=upper_bound(all(b),a[i]);
        if(right!=b.end()){
            lli rightVal=*right;
            if(mp.find(rightVal-a[i])!=mp.end()) death[a[i]]=min(death[a[i]],mp[rightVal-a[i]]);
        }
    }
    // debug(mp);
    // debug(death);
    vll v(k+1,0);
    fa(death){
        lli t=it.second;
        if(t!=1e18) v[t]++;
    }
    lli d=0;
    f(i,k){
        lli sec=i+1;
        d+=v[sec];
        cout<<n-d<<" ";
    }
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