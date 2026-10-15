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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;;
    while(t--){
        lli n;
        cin>>n;
        map<lli,lli> mpp;
        set<lli> left,right;
        f(i,n){
            lli x,y;
            cin>>x>>y;
            mpp.insert({x,y});
            left.insert(x),right.insert(y);
        }
        vll ans(n+1,-1);
        lli a=mpp[0];
        ans[2]=a;
        fa(left){
            if(right.find(it)==right.end()){
                ans[1]=it;
                break;
            }
        }
        ff(1,n-1,1){
            ans[i+2]=mpp[ans[i]];
        }
        ff(1,n+1,1) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}