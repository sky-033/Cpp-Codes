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
    lli n,x;
    cin>>n>>x;
    vll a(n);
    f(i,n) cin>>a[i];
    unordered_map<lli,vp> mp;
    f(i,n){
        for(lli j=i+1;j<n;j++){
            lli sum=a[i]+a[j];
            mp[sum].push_back({i+1,j+1});
        }
    }

    fa(mp){
        lli sum1=it.first;
        lli sum2=x-sum1;
        if(mp.find(sum2)==mp.end()) continue;
        vp v1=mp[sum1],v2=mp[sum2];
        for(auto &it1:v1){
            for(auto &it2:v2){
                lli i1=it1.first,i2=it1.second,i3=it2.first,i4=it2.second;
                if(i1!=i2 && i1!=i3 && i1!=i4 && i2!=i3 && i2!=i4 && i3!=i4){
                    cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<endl;
                    return;
                }
            }
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;
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