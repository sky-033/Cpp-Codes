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
const lli N=1e3+1;
const lli M=1e9+7; 

lli solve(lli indx,lli k,vvll &dp,vll &op,vll &c){
    if(indx<0) return 0;
    // if(k==0) return 0;
    if(dp[indx][k]!=-1) return dp[indx][k];
    lli maxi=solve(indx-1,k,dp,op,c);
    if(k>=op[indx]) maxi=max(maxi,solve(indx-1,k-op[indx],dp,op,c)+c[indx]);
    return dp[indx][k]=maxi;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    vll d(N,N);
    d[1]=0;
    ff(1,N,1){
        for(lli x=1;x<=i;x++) {
            lli j=i+i/x;
            if(j<N) d[j]=min(d[j],d[i]+1LL);
        }
    }
    while(t--){
        lli ans=0;
        lli n,k,K=0;
        cin>>n>>k;
        vll b(n),op(n),c(n);
        f(i,n){
            cin>>b[i];
            op[i]=d[b[i]];
            K+=op[i];
        }
        k=min(k,K);
        f(i,n) cin>>c[i];
        vvll dp(n+1,vll (k+1,-1));
        cout<<solve(n-1,k,dp,op,c)<<"\n";
    }
    return 0;
}