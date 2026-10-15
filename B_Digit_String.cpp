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
    string s;
    cin>>s;
    lli ans=0;
    if(s.size()==1 && (s[0]=='4' || s[0]=='8')){
        cout<<1<<endl;
        return;
    }

    lli ct1=0,ct2=0,ct4=0,ct3=0;
    fa(s){
        if(it=='4') ct4++;
    }
    fa(s){
        if(it=='1') ct1++;
        if(it=='2') ct2++;
        if(it=='3') ct3++;
        
        if(it=='2'){
            if(ct1>=1){
                ct2=0;
                ans++;
                ct1--;
            }
            else if(ct3>=1){
                ct2=0;
                ans++;
                ct3--;
            }
        }
    }
    ans+=ct4;
    
    //ans+=min(ct2,ct1+ct3);
    cout<<ans<<endl;
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