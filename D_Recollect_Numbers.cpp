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
    lli n,k;
    cin>>n>>k;
    if(k<n || k>2*n-1){
        no;
        return;
    }
    yes;
    if(k==n){
        ff(1,n+1,1) cout<<i<<" "<<i<<" ";
        cout<<endl;
        return;
    }
    lli waste=k-n;
    lli pair=2*n-1-k;
    ff(1,pair+1,1) cout<<i<<" "<<i<<" ";
    lli rem=n-pair;
    if(rem>=3){
        ff(pair+1,pair+4,1) cout<<i<<" ";
        lli val=pair+1;
        cout<<val<<" ";
        val++;
        lli r=pair+4;
        while(r<=n){
            cout<<r<<" "<<val<<" ";
            val++;
            r++;
        }
        while(val<=n){
            cout<<val<<" ";
            val++;
        }
    }
    else{
        ff(pair+1,n+1,1) cout<<i<<" ";
        ff(pair+1,n+1,1) cout<<i<<" ";
    }
    cout<<endl;
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