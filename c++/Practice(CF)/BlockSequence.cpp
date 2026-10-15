#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vpw vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

lli dp[N];

lli func(lli indx,vll &a){
    if(indx==a.size()) return 0;
    if(indx>a.size()) return 1e9;
    if(dp[indx]!=-1) return dp[indx];
    lli ways=func(indx+1,a)+1;
    if(indx+a[indx]<a.size()) ways=min(ways,func(indx+a[indx]+1,a));
    return dp[indx]=ways;
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
        for(lli i=0;i<=n;i++) dp[i]=-1;
        vll a(n);
        f(i,n) cin>>a[i];
        cout<<func(0,a)<<endl;
    }
    return 0;
}