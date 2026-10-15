#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=5005;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

string a,b;
lli dp[N][N];

lli rec(lli i,lli j){
    lli n=a.size(),m=b.size();

    if(i==n) return m-j;
    if(j==m) return n-i;
    if(dp[i][j]!=-1) return dp[i][j];


    if(a[i]==b[j]) return dp[i][j]=rec(i+1,j+1);
    
    return dp[i][j]=1+min({
        rec(i+1,j),     // delete
        rec(i,j+1),     // insert
        rec(i+1,j+1)    // replace
    });

}
void solve(){
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,0)<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}