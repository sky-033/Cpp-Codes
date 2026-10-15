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

lli binExpItr(lli a,lli b){
    lli ans=1;
    while(b){
        if(b&1) ans=(ans*a);
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli k,x;
        cin>>k>>x;
        lli val=binExpItr(2,k);
        lli a=x,b=2*val-a;
        vll ans;
        while(a!=b){
            if(a<b){
                ans.push_back(1);
                b-=a;
                a*=2;
            }
            else{
                ans.push_back(2);
                a-=b;
                b*=2;
            }
        }
        cout<<ans.size()<<"\n";
        reverse(all(ans));
        fa(ans) cout<<it<<" ";
        cout<<"\n";
    }
    return 0;
}