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
        lli n,k,l,r;
        cin>>n>>k>>l>>r;
        vll a(n);
        f(i,n) cin>>a[i];
        map<lli,lli> mp,mp1;
        lli L=0,R=0,ans=0;
        while(R<n){
            mp[a[R]]++;
            while(mp.size()>k){
                mp[a[L]]--;
                if(mp[a[L]]==0) mp.erase(a[L]);
                L++;
            }
            lli len=R-L+1;
            if(len>=l){
                ans+=max(0LL,min(len,r)-l+1);
            }
            R++;
        }
        L=0,R=0;
        k--;
        while(R<n){
            if(k<=0) break;
            mp1[a[R]]++;
            while(mp1.size()>k){
                mp1[a[L]]--;
                if(mp1[a[L]]==0) mp1.erase(a[L]);
                L++;
            }
            lli len=R-L+1;
            if(len>=l){
                ans-=max(0LL,min(len,r)-l+1);
            }
            R++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}