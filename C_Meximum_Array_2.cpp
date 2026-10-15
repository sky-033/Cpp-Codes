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
    lli n,k,q;
    cin>>n>>k>>q;
    vll c1(n+1,0),c2(n+1,0);
    vll a(n+1,-1);
    vp c11,c22;
    while(q--){
        lli c,l,r;
        cin>>c>>l>>r;
        if(c==1){
            for(lli i=l;i<=r;i++) c1[i]=1;
            c11.push_back({l,r});
        }
        else{
            for(lli i=l;i<=r;i++) c2[i]=1;
            c22.push_back({l,r});
        }
    }
    ff(1,n+1,1){
        if(c1[i]==1 && c2[i]==1) a[i]=k+1;
    }
    fa(c11){
        lli l=it.first,r=it.second;

        for(lli i=l;i<=r;i++){
            if(a[i]==-1) a[i]=k;
        }

    }
    fa(c22){
        lli l=it.first,r=it.second;
        for(lli i=l;i<=r;i++){
            if(a[i]==-1){
                a[i]=i%k;
            }
        }
    }
    ff(1,n+1,1){
        if(a[i]==-1) a[i]=0;
    }
    ff(1,n+1,1) cout<<a[i]<<" ";
    cout<<endl;

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