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
    vll a(n),b(n),pos(n+1);
    f(i,n){
        cin>>a[i];
        pos[a[i]]=i+1;
    }
    map<lli,lli> mp;
    f(i,n){
        cin>>b[i];
        if(b[i]!=-1) mp[b[i]]++;
    }
    fa(mp){
        if(it.second>1){
            no;
            return;
        }
    }

    lli L=n-k+1;
    lli R=k;

    f(i,n){
        lli cur=i+1;
        if(b[i]==-1) continue;
        if(L>R || cur<L || cur>R){
            if(b[i]!=a[i]){
                no;
                return;
            }
        }
        else{
            lli posi=pos[b[i]];
            if(posi<L || posi>R){
                no;
                return;
            }
        }
    }

    yes;
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