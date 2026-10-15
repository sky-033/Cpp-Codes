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

bool check(lli n,lli m,lli d,lli mid){
    if(mid>=n) return true;
    lli left=n-mid;
    lli box=(n-mid)/mid;
    if((n-mid)%mid!=0) box++;
    lli wt=box*m;
    if(wt<=d) return true;
    return false;
}

void solve(){
    lli n,m,d;
    cin>>n>>m>>d;
    lli l=1,h=n;
    while(h-l>1){
        lli mid=(l+h)/2;
        if(check(n,m,d,mid)){
            h=mid;
        }
        else{
            l=mid;
        }
    }
    if(check(n,m,d,l)) cout<<l<<endl;
    else cout<<h<<endl;
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