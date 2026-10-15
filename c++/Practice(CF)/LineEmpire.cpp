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
        lli n,a,b;
        cin>>n>>a>>b;
        vll x(n);
        f(i,n) cin>>x[i];
        vll prefix(n,0);
        prefix[0]=x[0];
        ff(1,n,1) prefix[i]=prefix[i-1]+x[i];
        lli cost=x[0]*b;
        lli cap=0;
        ff(1,n,1){
            lli c1=(prefix[n-1]-prefix[i-1]-(n-i)*cap)*b;
            lli c2=(x[i-1]-cap)*a+(prefix[n-1]-prefix[i-1]-(n-i)*x[i-1])*b;
            if(c1>=c2){
                cost+=(x[i-1]-cap)*a;
                cap=x[i-1];
                
            }
            cost+=(x[i]-cap)*b;
        }
        cout<<cost<<"\n";
    }
    return 0;
}