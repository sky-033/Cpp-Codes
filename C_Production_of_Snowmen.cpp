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
    vll a(n),b(n),c(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>b[i];
    f(i,n) cin>>c[i];
    lli c1=0,c2=0;
    f(i,n){
        bool flag1=true,flag2=true;
        f(j,n){
            if(a[j]>=b[(i+j)%n]){
                flag1=false;
                break;
            }
        }
        f(j,n){
            if(b[j]>=c[(i+j)%n]){
                flag2=false;
                break;
            }
        }
        if(flag1) c1++;
        if(flag2) c2++;
    }
    cout<<n*c1*c2<<endl;
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