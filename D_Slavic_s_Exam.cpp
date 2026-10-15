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
    lli q=0;
    lli indx=0;
    lli siz=t.size();
    bool flag=false;
    f(i,s.size()){
        if(indx<t.size() && s[i]==t[indx]){
            siz--;
            indx++;
        }
        if(s[i]=='?'){
            s[i]=t[indx];
            indx++;
        }
        if(indx>=t.size()){
            flag=true;
            break;
        }
    }
    f(i,s.size()){
        if(s[i]=='?') s[i]='a';
    }
    if(flag){
        yes;
        cout<<s<<endl;
        return;
    }
    no;
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