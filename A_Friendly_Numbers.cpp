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
lli digitSum(lli n) {
    n = llabs(n);   
    lli sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}
void solve(){
    lli n;
    cin>>n;
    string s=to_string(n);
    lli digit=s.size();
    digit*=9;
    lli ct=0;
    for(lli i=0;i<=digit+1;i++){
        lli val=n+i;
        if(val-digitSum(val)==n) ct++;
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