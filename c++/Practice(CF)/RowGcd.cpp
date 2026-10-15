#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    vll a(n),b(m);
    f(i,n) cin>>a[i];
    f(i,m) cin>>b[i];
    sor(a);
    lli g=0;
    if(n==1) g=a[0];
    else{
        f(i,n-1) g=__gcd(g,a[i+1]-a[i]);
    }
    if(n==1){
        f(i,m) cout<<a[0]+b[i]<<" ";
        cout<<"\n";
    }
    else{
        f(i,m){
            lli val=b[i]+a[0];
            cout<<__gcd(g,val)<<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}