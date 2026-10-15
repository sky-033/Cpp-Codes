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

lli solve(lli indx,vll &dp,lli n,vll &a,vvll &pos){
    if(indx>=n) return 0;
    if(dp[indx]!=-1) return dp[indx];
    lli ans=solve(indx+1,dp,n,a,pos);               //not take
    lli val=a[indx];
    lli in=lower_bound(all(pos[val]),indx)-pos[val].begin();
    if(in+val-1<pos[val].size()){
        ans=max(ans,val+solve(pos[val][in+val-1]+1,dp,n,a,pos));      //take
    }
    return dp[indx]=ans;
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
        vll dp(n+1,-1);
        vll a(n);
        vvll pos(n+1);
        f(i,n){
            cin>>a[i];
            pos[a[i]].push_back(i);
        }
        cout<<solve(0,dp,n,a,pos)<<'\n';
    }
    return 0;
}