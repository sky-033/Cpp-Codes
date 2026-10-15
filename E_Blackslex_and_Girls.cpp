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
    lli n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    vll p(n);
    f(i,n) cin>>p[i];
    lli total_sum=accumulate(all(p),0LL);
    if(total_sum>x+y){
        no;
        return;
    }
    lli sum_x=0,sum_y=0,ct0=0,ct1=0;
    f(i,n){
        if(s[i]=='0'){
            ct0++;
            sum_x+=(p[i]/2+1);
        }
        else{
            ct1++;
            sum_y+=(p[i]/2+1);
        }
    }
    if(ct0>0 && sum_x>x){
        no;
        return;
    }
    if(ct1>0 && sum_y>y){
        no;
        return;
    }
    if(ct1==0){
        if(x-y<n){
            no;
            return;
        }
    }
    if(ct0==0){
        if(y-x<n){
            no;
            return;
        }
    }
    yes;
    return;
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