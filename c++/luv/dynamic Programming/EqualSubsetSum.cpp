#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
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

lli dp[201][20001];

bool func(lli indx,lli sum,vll &a){
    if(sum==0) return true;
    if(indx<0) return false;
    if(dp[indx][sum]!=-1) return dp[indx][sum];
    bool isPossible=func(indx-1,sum,a);
    if(sum-a[indx]>=0) isPossible|=func(indx-1,sum-a[indx],a);
    return dp[indx][sum]=isPossible;

}

void printSet(lli indx,lli sum_left,vll &a){
    if(indx<0) return;
    if(func(indx-1,sum_left,a)) printSet(indx-1,sum_left,a);
    else{
        cout<<a[indx]<<" ";
        printSet(indx-1,sum_left-a[indx],a);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vll a(n);
    f(i,n) cin>>a[i];
    lli sum=accumulate(all(a),0LL);
    if(sum%2==0){
        sum/=2;
        if(func(n-1,sum,a)){
            cout<<"YES"<<endl;
            printSet(n-1,sum,a);
        }
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}