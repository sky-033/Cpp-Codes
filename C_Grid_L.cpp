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
    lli p,q;
    cin>>p>>q;

    lli k=4*q+2*p+1;   // n(m+1)+m(n+1)==2*q+p && q<=min(n(m+1),m(n+1))
    for(lli i=3;i*i<=k;i++){
        if(k%i==0){
            lli a=i,b=k/i;
            lli n=(a-1)/2,m=(b-1)/2;
            if(n>0 && m>0 && abs(a-b)<=2*p){
                cout<<n<<" "<<m<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
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