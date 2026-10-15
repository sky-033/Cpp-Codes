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
    lli n;
    cin>>n;

    set<lli> medians,small,large;

    for(lli i=3*n-1;i>0;i-=2){
        medians.insert(i);
        if(medians.size()==n) break;
    }
    ff(1,3*n+1,1){
        if(medians.find(i)==medians.end()){
            small.insert(i);
        }
        if(small.size()==n) break;
    }

    for(lli i=3*n;i>0;i-=2){
        large.insert(i);
        if(large.size()==n) break;
    }

    vll v1,v2,v3;
    fa(small) v1.push_back(it);
    fa(medians) v2.push_back(it);
    fa(large) v3.push_back(it);
    //debug(v1,v2,v3);


    f(i,n){
        cout<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<" ";
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