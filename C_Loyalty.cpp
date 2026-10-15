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
    lli n,x;
    cin>>n>>x;
    vll a(n),order;
    f(i,n) cin>>a[i];
    sor(a);
    lli l=0,h=n-1,sum=0,bonus=0;
    while(l<=h){
        if((sum+a[h])/x != sum/x){
            order.push_back(a[h]);
            bonus+=a[h];
            sum+=a[h];
            h--;
        }
        else{
            order.push_back(a[l]);
            sum+=a[l];
            l++;
        }
    }
    cout<<bonus<<endl;
    fa(order) cout<<it<<" ";
    cout<<endl;
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