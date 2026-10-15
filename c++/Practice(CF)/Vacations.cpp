#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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
lli dp[3][101];
// 0->rest day
// 1->contest
// 2->sport
lli solve(lli indx,lli prev,lli n,vll &a){
    if(indx==n) return 0;
    if(dp[prev][indx]!=-1) return dp[prev][indx];
    lli restDays=solve(indx+1,0,n,a)+1;
    if(prev!=1 && (a[indx]==1 || a[indx]==3)) restDays=min(restDays,solve(indx+1,1,n,a));
    if(prev!=2 && (a[indx]==2 || a[indx]==3)) restDays=min(restDays,solve(indx+1,2,n,a));
    return dp[prev][indx]=restDays;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,n,a)<<"\n";
    return 0;
}