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
    lli q;
    cin>>q;
    while(q--){
        lli k;
        cin>>k;
        if(k<=9){
            cout<<k<<endl;
           continue;
        }
        lli K=k;
        lli d=1,ct=9;
        while(k>=d*ct){
            k-=ct*d;
            d++;
            ct*=10;
        }
        debug(d);
        if(k==0){
            cout<<9<<endl;
            continue;
        }
        lli num=1;
        lli D=d-1;
        while(D>0){
            num*=10;
            D--;
        }
        debug(num);
        lli indx=(k-1)/d;
        num+=indx;
        lli pos=(k-1)%d;
        string s=to_string(num);
        cout<<s[pos]<<endl;
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