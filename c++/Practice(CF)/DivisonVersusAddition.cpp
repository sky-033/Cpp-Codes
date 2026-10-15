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
        lli n,q;
        cin>>n>>q;
        vll a(n),prefix(n+1,0),minus(n+1,0);
        f(i,n) cin>>a[i]; 
        ff(1,n+1,1){
            prefix[i]=prefix[i-1]+bitlen(a[i-1])-1;
            minus[i]=minus[i-1];
            if((a[i-1]&(a[i-1]-1))){                //a[i-1] is not a power of two
                if((a[i-1]-1)&(a[i-1]-2)) prefix[i]++;  // a[i-1]-1 is not a power of two
                else minus[i]++;
            }
        }
        while(q--){
            lli l,r;
            cin>>l>>r;
            cout<<prefix[r]-prefix[l-1]+(minus[r]-minus[l-1])/2<<"\n";
        }
      

    }
    return 0;
}