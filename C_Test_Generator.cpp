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

vll opts;
lli modpow(lli a, lli b) {
    lli res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}


void solve(){
    opts.clear();
    lli s,m;
    cin>>s>>m;
    if(m%2==0 && s%2==1){
        cout<<-1<<endl;
        return;
    }
    
    f(i,62){
        if((1LL<<i)&m){
            opts.push_back(i);
        }
    }
    sort(all(opts));
    reverse(all(opts));
    lli sum=0;
    f(i,1LL*opts.size()){
        opts[i]=pow(2,opts[i]);
        sum+=opts[i];
    }
    // debug(opts);
    lli ans=0;
    
        lli x=sum;
    fa(opts){
        
        if(it<=s){
            lli val=it;
            lli times=s/val;
            times=min(times,(x+s-1)/x);
            ans=max(times,ans);
            s-=times*val;
        }
        x-=it;
    
}
if(s!=0) cout<<-1<<endl;
else cout<<ans<<endl;
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