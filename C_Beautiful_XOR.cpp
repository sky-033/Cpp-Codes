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
#define sor(x) sort(all(x))
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
    lli a,b;
    cin>>a>>b;
    if(a==b) cout<<0<<endl;
    else if(bitlen(a)<bitlen(b)) cout<<-1<<endl;
    else{
        vll vec1;
        f(i,bitlen(a)){
            if((1<<i)&a) vec1.push_back(0);
            else vec1.push_back(1);
        }
        vll vec2;
        f(i,bitlen(a)){
            if((1<<i)&b) vec2.push_back(0);
            else vec2.push_back(1);
        }
        lli num1=0,num2=0;
        f(i,bitlen(a)){
            if(vec1[i]==1) num1|=(1<<i);
        }
        f(i,bitlen(a)){
            if(vec2[i]==1) num2|=(1<<i);
        }
        cout<<2<<endl;
        cout<<num1<<" "<<num2<<endl;
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