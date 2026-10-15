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
    string s,t;
    cin>>s>>t;
    lli n=s.size();
    map<char,lli> ms,mt;
    fa(s) ms[it]++;
    fa(t) mt[it]++;
    f(i,s.size()){
        if(mt[s[i]]<ms[s[i]]){
            cout<<"Impossible"<<endl;
            return;
        }
    }
    f(i,s.size()){
        mt[s[i]]-=ms[s[i]];
        ms[s[i]]=0;
    }
    string z="";
    f(i,n){
        for(char k='a';k<s[i];k++){
            while(mt[k]>0){
                z+=k;
                mt[k]--;
            }
        }
        z+=s[i];
    }
    for(char k='a';k<='z';k++){
        while(mt[k]>0){
            z+=k;
            mt[k]--;
        }
    }
    cout<<z<<endl;
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