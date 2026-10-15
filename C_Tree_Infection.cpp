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

bool check(vll &siz,lli mid){
    lli n=siz.size();
    lli extra=mid-n;
    f(i,n){
        lli time=mid-(i+1);
        extra-=max(0LL,(siz[i]-1)-time);
    }
    return extra>=0;
}

void solve(){
    lli n;
    cin>>n;
    vll child(n+1,0),siz;
    f(i,n-1){
        lli x;
        cin>>x;
        child[x]++;
    }
    siz.push_back(1);
    ff(1,n+1,1){
        if(child[i]>0) siz.push_back(child[i]);
    }
    sort(all(siz));
    reverse(all(siz));
    // debug(siz);
    lli l=siz.size(),h=n;
    lli mid;
    while(h-l>1){
        mid=l+(h-l)/2;
        if(check(siz,mid)) h=mid;
        else l=mid+1;
    }
    if(check(siz,l)) cout<<l<<endl;
    else cout<<h<<endl;
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