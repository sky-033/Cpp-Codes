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

bool check(lli mid,vll &a,lli k){
    lli n=a.size();
    lli K=0;
    lli sum=0;
    f(i,n){
        if(a[i]>mid) return false;
        if(sum+a[i]<=mid) sum+=a[i];
        else{
            K++;
            sum=a[i];
        }
    }
    if(sum!=0) K++;
    return k-K>=0;
}
void solve(){
    lli n,k;
    cin>>n>>k;
    vll a(n);
    f(i,n) cin>>a[i];
    lli l=0,h=accumulate(all(a),0LL),mid;
    while(h-l>1){
        mid=(l+h)/2;
        if(check(mid,a,k)) h=mid;
        else l=mid+1;
    }
    if(check(l,a,k)) cout<<l<<endl;
    else cout<<h<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}