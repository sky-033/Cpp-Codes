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

string s1,s2;
lli n,m;

lli solve(lli i,lli j,vvll &dp,lli &maxLen){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    lli ans=0;
    if(s1[i]==s2[j]) ans=1+solve(i-1,j-1,dp,maxLen);

    maxLen=max(maxLen,ans);
    return dp[i][j]=ans;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        n=s1.size(),m=s2.size();
        vvll dp(n,vll(m,-1));
        lli maxLen=0;
        f(i,n){
            f(j,m){
                maxLen=max(maxLen,solve(i,j,dp,maxLen));
            }
        }
        cout<<maxLen<<"\n";
    }
    return 0;
}

// lli maxLen = 0;
// vvll dp(n+1, vll(m+1, 0));
// for(int i=1;i<=n;i++){
//     for(int j=1;j<=m;j++){
//         if(s1[i-1]==s2[j-1]){
//             dp[i][j] = 1 + dp[i-1][j-1];
//             maxLen = max(maxLen, dp[i][j]);
//         }
//     }
// }
