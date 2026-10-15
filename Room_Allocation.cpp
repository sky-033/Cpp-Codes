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
    vp vec;
    f(i,n){
        lli x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    vector<pair<pair<lli,lli>,lli>> v;
    lli indx=1;
    fa(vec){
        v.push_back({{it.first,it.second},indx++});
    }
    sort(all(v));
    set<pair<lli,lli>> st;
    map<lli,lli> mp;
    lli room=1;
    fa(v){
        lli x=it.first.first;
        lli y=it.first.second;
        lli indx=it.second;
        if(st.empty()){
            mp[indx]=room;
            st.insert({y,room++});
            continue;
        }
        auto itt=st.begin();
        if(itt->first<x){
            lli roomNo=itt->second;
            st.erase(itt);
            mp[indx]=roomNo;
            st.insert({y,roomNo});
        }
        else{
            mp[indx]=room;
            st.insert({y,room++}); 
        }
    }
    lli k=-1;
    fa(mp){
        k=max(k,it.second);
    }
    cout<<k<<endl;
    fa(mp) cout<<it.second<<" ";
    cout<<endl;

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