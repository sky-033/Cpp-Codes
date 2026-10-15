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
const lli M=998244353; 

lli dp[2][101];

lli solve(lli indx,lli choice,vll &a,vll &b,lli n){
    if(indx==n-1) return 1;
    if(dp[choice][indx]!=-1) return dp[choice][indx];
    lli curA,curB,ans=0;
    if(choice==0){
        curA=a[indx];
        curB=b[indx];
    }
    else{
        curA=b[indx];
        curB=a[indx];
    }
    if(a[indx+1]>=curA && b[indx+1]>=curB) ans=(ans+solve(indx+1,0,a,b,n))%M;
    if(b[indx+1]>=curA && a[indx+1]>=curB) ans=(ans+solve(indx+1,1,a,b,n))%M;
    return dp[choice][indx]=ans%M;
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
        vll a(n),b(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        memset(dp,-1,sizeof(dp));
        lli val=(solve(0,0,a,b,n)+solve(0,1,a,b,n))%M;
        cout<<val<<"\n";
    }
    return 0;
}