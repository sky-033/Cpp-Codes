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

vvll multiples;
lli dp[2001][2001];
lli func(lli indx,lli k){
    if(k==1) return 1;
    if(dp[indx][k]!=-1) return dp[indx][k];
    lli ways=0;
    fa(multiples[indx]){
        ways=(ways+func(it,k-1))%M;
    }
    return dp[indx][k]=ways;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    multiples.assign(n+1,{});
    for(lli i=1;i<=n;i++){
        for(lli j=i;j<=n;j+=i) multiples[i].push_back(j);
    }
    lli ans=0;
    ff(1,n+1,1){
        ans+=func(i,k);
    }
    cout<<ans%M<<'\n';
    return 0;
}