#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define lli long long

#define bitlen(x) 64-__builtin_clzll(x)



#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
   // debug(bitlen(n));
    if((n&(n+1))==0){
        cout<<((long long)bitlen(n))*(n+1)/2<<endl;
        return;
    }

    lli ct=0;
    //yes;
    for(lli i=50;i>=0;i--){
        if((1LL<<i)&n){
            lli val=1LL<<i;
            val--;
            lli num=n&((1LL<<(i+1))-1);
            ct+=(num-val);
            ct+=((bitlen(val))*(val+1)/2);
        }
    }
    cout<<ct<<endl;
    
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