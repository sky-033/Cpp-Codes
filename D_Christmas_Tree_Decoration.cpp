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
const lli M=998244353;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    vll fact(53);
    fact[0]=1;
    for(lli i=1;i<=52;i++) fact[i]=fact[i-1]*i%M;
    lli n;
    cin>>n;
    vll a(n+1),times(n+1,0);
    f(i,n+1) cin>>a[i];
    lli sum=accumulate(all(a),0LL);
    if(n==1){
        cout<<1<<endl;
        return;
    }
    ff(1,n+1,1){
        lli val=sum-a[i];
        if(val/(n-1)+1<a[i]){
            cout<<0<<endl;
            return;
        }
        if(val/(n-1)>=a[i]) times[i]=n;
        else{
            lli temp=val%(n-1);
            times[i]=temp+1;
        }
    }
    lli ct=0;
    map<lli,lli> mp;
    ff(1,n+1,1){
        if(times[i]==n) ct++;
        else{
            mp[times[i]]++;
        }
    }
    lli ans=fact[ct];
    fa(mp){
        lli c=it.second;
        lli v=it.first;
        if(c>v){
            cout<<0<<endl;
            return;
        }
        while(c>0){
            ans=(ans*v)%M;
            c--;
            v--;
        }
    }
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