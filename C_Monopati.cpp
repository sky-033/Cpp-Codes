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
    vvll a(2,vll (n));
    f(i,2){
        f(j,n) cin>>a[i][j];
    }
    vll mina1(n),maxa1(n),mina2(n),maxa2(n);
    f(i,n){
        if(i==0){
            mina1[i]=a[0][i];
            maxa1[i]=a[0][i];
            continue;
        }
        mina1[i]=min(mina1[i-1],a[0][i]);
        maxa1[i]=max(maxa1[i-1],a[0][i]);
    }
    for(lli i=n-1;i>=0;i--){
        if(i==n-1){
            mina2[i]=a[1][i];
            maxa2[i]=a[1][i];
            continue;
        }
        mina2[i]=min(mina2[i+1],a[1][i]);
        maxa2[i]=max(maxa2[i+1],a[1][i]);
    }
    // vll maxii(n+1,-1);
    // vll minii(n+1,1e9);
    // f(i,n){
    //     lli mini=min(mina1[i],mina2[i]);
    //     lli maxi=max(maxa1[i],maxa2[i]);
    //     lli val=2*n-maxi;

    // }
    vll max_M(2*n+1,0); 
    f(i,n){ 
        lli mini_k=min(mina1[i],mina2[i]); 
        lli maxi_k=max(maxa1[i],maxa2[i]); 
        max_M[maxi_k]=max(max_M[maxi_k],mini_k);
    }
    // debug(max_M);
    lli cnt=0;
    lli maxi=0; 
    for(lli i=1;i<=2*n;i++){
        maxi=max(maxi,max_M[i]);
        max_M[i]=maxi;
    }
    for(lli i=1;i<=2*n;i++){
        cnt+=min(i,max_M[i]);
    }
    cout<<cnt<<endl;
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