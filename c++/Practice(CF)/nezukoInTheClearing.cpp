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

bool check(lli x,lli d,lli h){
    lli total=h+x;
    lli grps=x+1;
    lli s=d/grps;
    lli rem=d%grps;
    lli high=rem;
    lli low=grps-rem;
    lli damage=low*(s*(s+1))/2+high*(s+1)*(s+2)/2;
    return total>damage;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli h,d;
        cin>>h>>d;
        lli l=0,hi=d,x;
        while(hi-l>1){
            x=(l+hi)/2;
            if(check(x,d,h)){
                hi=x;
            }
            else l=x+1;
        }
        if(check(l,d,h)) cout<<d+l<<"\n";
        else cout<<d+hi<<"\n";
    }
    return 0;
}