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
struct DSU{
    vll size,parent;
    int n;
    lli current_total=0;
    void make(lli n){
        size.resize(n+1,1),parent.resize(n+1);
        ff(1,n+1,1) parent[i]=i;
        current_total=0;
    }
    lli find(lli v){
        if(v==parent[v]) return v;
        return parent[v]=find(parent[v]);        //path compression
    }
    void Union(lli a,lli b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);       //union by size
            current_total+=(size[a]*size[b]);
            parent[b]=a;
            size[a]+=size[b];
        }

    }
};
void solve(){
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    map<lli,vp> mp;
    f(i,n-1){
        lli dif=abs(a[i]-a[i+1]);
        mp[dif].push_back({a[i],a[i+1]});
    }
    struct DSU d;
    d.make(n);
    vll ans;
    for(lli i=n-1;i>=1;i--){
        fa(mp[i]){
            lli u=it.first,v=it.second;
            d.Union(u,v);
        }
        ans.push_back(d.current_total);
    }
    reverse(all(ans));
    fa(ans) cout<<it<<" ";
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