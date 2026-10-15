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
    lli n;
    cin>>n;
    vll a(n),b(n);
    vll pos(n+1,-1);
    f(i,n){
        cin>>a[i];
        pos[a[i]]=i;
    }
    lli ct=0;
    map<lli,lli> mp;
    f(i,n){
        cin>>b[i];
        mp[a[i]]=b[i];
        if(a[i]==b[i]) ct++;
    }
    if(ct>=2){
        cout<<-1<<endl;
        return;
    }
    if(ct==1 && n%2==0){
        cout<<-1<<endl;
        return;
    }
    vll check(n+1);
    f(i,n) check[a[i]]=b[i];
    f(i,n){
        if(check[b[i]]!=a[i]){
            cout<<-1<<endl;
            return;
        }
    }
    vp store;
    if(n&1){
        f(i,n){
            if(a[i]==b[i] && i!=n/2){
                pos[a[i]]=n/2;
                pos[a[n/2]]=i;
                swap(a[i],a[n/2]);
                store.push_back({i,n/2});
                
            }
        }
    }
    // debug(store);
    // debug(pos);
    f(i,n/2){
        if(n&1 && i==n/2) break;
        // debug(pos);
        lli a1=a[i],b1=mp[a[i]];
        // debug(a1,b1);
        lli posi=pos[b1];
        lli ops=n-i-1;
        // debug(posi,ops);
        if(posi!=ops){
            store.push_back({posi,ops});
            pos[b1]=ops;
            pos[a[ops]]=posi;
            swap(a[posi],a[ops]);
        }
    }
    cout<<store.size()<<endl;
    fa(store) cout<<it.first+1<<" "<<it.second+1<<endl;

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