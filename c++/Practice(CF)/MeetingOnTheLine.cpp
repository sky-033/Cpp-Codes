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

lli tern(vp& a,lli n,lli x){
    lli maxi=-1.0;
    f(i,n){
        maxi=max(maxi,a[i].second+abs(a[i].first-x));
    }
    return maxi;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll x(n),t(n);
        vp a(n);
        f(i,n) cin>>x[i];
        f(i,n) cin>>t[i];
        f(i,n) a[i]={x[i],t[i]};
        sor(a);
        lli l=a[0].first,h=a[n-1].first;
        while(h-l>3){
            lli m1=l*1.0+(h-l)/3.0;
            lli m2=h*1.0-(h-l)/3.0;
            if(tern(a,n,m1)<tern(a,n,m2)) h=m2;
            else l=m1;
        }
        lli mini=1e18,ans=-1;
        ff(l,h+1,1){
            if(mini>tern(a,n,i)){
                ans=i;
                mini=tern(a,n,i);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}