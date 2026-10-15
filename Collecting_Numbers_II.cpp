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
    lli n,m;
    cin>>n>>m;
    vll a(n+1);
    f(i,n) cin>>a[i+1];
    vll pos(n+1,0);
    f(i,n){
        pos[a[i+1]]=i+1;
    }
    lli ct=1;
    ff(2,n+1,1){
        lli posPrev=pos[i-1],posCur=pos[i];
        if(posCur<posPrev) ct++;
    }
    while(m--){
        lli x,y;
        cin>>x>>y;
        lli v1=a[x],v2=a[y];
        set<lli> affected={v1,v1-1,v2,v2-1};
        fa(affected){
            if(it>=1 && it<n){
               if(pos[it]>pos[it+1]) ct--; 
            }
        }
        swap(a[x],a[y]);
        swap(pos[v1],pos[v2]);
        fa(affected){
            if(it>=1 && it<n){
               if(pos[it]>pos[it+1]) ct++; 
            }
        }
        cout<<ct<<endl;
    }
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