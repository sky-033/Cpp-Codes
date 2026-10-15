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
    string s;
    cin>>s;
    lli n=s.size();
    lli ct=0;
    if(s[0]=='u'){
        ct++;
        s[0]='s';
    }
    if(s[n-1]=='u'){
        ct++;
        s[n-1]='s';
    }
    // debug(ct);
    ff(2,n-1,1){
        if(s[i]=='u' && s[i-1]=='u' && s[i+1]=='u'){
            s[i]='s';
            ct++;
        }
        else if(s[i]=='u' && s[i+1]=='u'){
            s[i+1]='s';
            ct++;
        }
        else if(s[i]=='u' && s[i-1]=='u'){
            s[i-1]='s';
            ct++;
        }
    }
    cout<<ct<<endl;
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