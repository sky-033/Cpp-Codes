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

lli dp[101][101][101];
string s1,s2,s3;
lli n,m,k;
lli solve(lli i,lli j,lli l){
    if(i>=n || j>=m || l>=k) return 0;
    if(dp[i][j][l]!=-1) return dp[i][j][l];

    lli ans=solve(i+1,j,l);
    ans=max(ans,solve(i,j+1,l));
    ans=max(ans,solve(i,j,l+1));

    if(s1[i]==s2[j] && s2[j]==s3[l]) ans=max(ans,1+solve(i+1,j+1,l+1));

    return dp[i][j][l]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2>>s3;
        n=s1.size(),m=s2.size(),k=s3.size();
        f(i,n){
            f(j,m){
                f(l,k) dp[i][j][l]=-1;
            }
        }
        cout<<solve(0,0,0)<<"\n";
    }
    return 0;
}