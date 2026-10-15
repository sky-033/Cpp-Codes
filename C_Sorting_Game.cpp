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
    string s;
    cin>>s;
    bool flag=true;
    f(i,n-1){
        if(s[i]=='1' && s[i+1]=='0'){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"Bob"<<endl;
        return;
    }
    lli ct0=0;
    f(i,n){
        if(s[i]=='0') ct0++;
    }
    vll v;
    for(lli i=ct0;i<n;i++){
        if(s[i]=='0') v.push_back(i+1);
    }
    for(lli i=0;i<ct0;i++){
        if(s[i]=='1') v.push_back(i+1);
    }
    sort(all(v));
    cout<<"Alice"<<endl;
    cout<<v.size()<<endl;
    fa(v) cout<<it<<" ";
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