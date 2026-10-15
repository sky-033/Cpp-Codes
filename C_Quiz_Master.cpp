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


vector<vector<lli>> factors(N+1);
void sieve() {
    for(lli i=1;i<=N;++i) {
        for(lli j=i;j<=N;j+=i){
            factors[j].push_back(i);
        }  
    }
}

void solve(){
    lli n,m;
    cin>>n>>m;

    vll a(n);
    f(i,n) cin>>a[i];

    sort(all(a));
    map<lli,lli> mp;
    lli ans=1e9,l=0,ct=0;
    for(lli r=0;r<n;r++){
        fa(factors[a[r]]){
            if(it<=m){
                mp[it]++;
                if(mp[it]==1) ct++;
            }
        }
        while(l<=r && ct==m){
            ans=min(ans,a[r]-a[l]);
            fa(factors[a[l]]){
                if(it<=m){
                    mp[it]--;
                    if(mp[it]==0) ct--;
                }
            }
            l++;
        }
    }
    if(ans==1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
    return 0;
}