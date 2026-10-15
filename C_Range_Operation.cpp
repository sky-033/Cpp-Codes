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
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    vll prefix(n+1,0);
    prefix[1]=a[0];
    ff(1,n,1) prefix[i+1]=prefix[i]+a[i];
    lli mini=1e15,maxi=0;
    ff(1,n+1,1){
        // gain(r,l) = f(r)-g(l) = (l+r)*(r-l+1)-(prefix[r]-prefix[l-1]) = (r*r+r-prefix[r])-(l*l-l-prefix[l-1])
        lli fr=i*i+i-prefix[i];
        lli gl=i*i-i-prefix[i-1];
        mini=min(mini,gl);
        maxi=max(maxi,fr-mini);
    }
    cout<<prefix[n]+maxi<<endl;       //maxi=max(0,f(r)-g(l))
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