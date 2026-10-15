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

lli count(vll &a, vll &b,lli n,lli mid){
    lli total=0;
    f(i,n){
        if(a[i]>=mid) total+=(a[i]-mid)/b[i]+1;
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n),b(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
            lli l=0,h=1e9+1,mid,ans=l;
            while(l<=h){
                mid=(l+h)/2;
                if(count(a,b,n,mid)>=k){
                    ans=mid;
                    l=mid+1;
                }
                else h=mid-1;
            }
            // cout<<count(a,b,n,ans+1);
            cout<<ans<<" ";
            lli left=k-count(a,b,n,ans+1);
            lli temp=ans+1;
            // cout<<temp<<" ";
            lli ansT=0;
            f(i,n){
                if(a[i]>=temp){
                    lli cnt=(a[i]-temp)/b[i]+1;
                    // cout<<cnt<<" ";
                    if(cnt==1) ansT+=a[i];
                    else{
                        lli st=a[i]-(cnt-1)*b[i];
                        ansT+=cnt*(a[i]+st)/2;
                    }
                    
                }
            }
            ansT+=left*ans;
            cout<<ansT<<"\n";
    }
    return 0;
}