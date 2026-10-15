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
    vll a(n),b(n);
    lli ct1=0,ct2=0;
    f(i,n){
        cin>>a[i];
        ct1^=a[i];
    }
    f(i,n){
        cin>>b[i];
        ct2^=b[i];
    }
    if(ct1==ct2){
        cout<<"Tie"<<endl;
        return;
    }
    lli ct=ct1^ct2;
    lli maxi=-1;
    f(i,32){
        if(ct&(1<<i)) maxi=max(maxi,i);
    }
    for(lli i=n-1;i>=0;i--){
        if(((a[i]&(1<<maxi)) && !(b[i]&(1<<maxi))) || (!(a[i]&(1<<maxi)) && (b[i]&(1<<maxi)))){
            if(i%2==0) cout<<"Ajisai"<<endl;
            else cout<<"Mai"<<endl;
            return;
        }
    }

    
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