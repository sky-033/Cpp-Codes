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


vll factor(lli n){
    vll temp1;
    for(lli i=1;i*i<=n;i++){
        if(n%i==0) {
            temp1.push_back(i);
            if(n/i!=i) temp1.push_back(n/i);
        }
    }
    sor(temp1);
    return temp1;
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
        vll a(n+1);
        ff(1,n+1,1) cin>>a[i];
        vll op=factor(n);
        lli ans=1;
        fa(op){
            if(it==n) continue;
            lli k=it;
            bool flag=true;
            lli gcd=0;
            // for(lli i=1;i<=k;i++){
            //     unordered_set<lli> temp;
            //     for(lli j=i;j<=n;j+=k){
            //         temp.insert(a[j]);
            //     }
            //     if(temp.size()>1){
            //         auto cur=temp.begin();
            //         auto prv=cur;
            //         cur++;
            //         for(;cur!=temp.end();cur++,prv++){
            //             gcd=__gcd(gcd,abs(*cur-*prv));
            //         }
            //     }      
            // }
            for(lli i=1;i+k<=n;i++){
                gcd=__gcd(gcd,abs(a[i+k]-a[i]));
            }
            if(gcd!=1) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}