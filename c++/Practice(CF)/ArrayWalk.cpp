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
    int t;
    cin>>t;
    while(t--){
        lli n,k,z;
        cin>>n>>k>>z;
        vll a(n);
        f(i,n) cin>>a[i];
        vll prefix(n,0);
        prefix[0]=a[0];
        ff(1,n,1) prefix[i]=prefix[i-1]+a[i];
        lli ans=0,pair=a[0]+a[1];
        for(lli i=0;i<=k;i++) ans+=a[i];
        ff(0,k+1,1){
           if(i<n-1) pair=max(pair,a[i]+a[i+1]);
           lli left=k-i;
           left=min(z,left/2);
           ans=max(ans,prefix[i]+left*pair);
        }
        cout<<ans<<"\n";
    }
    return 0;
}