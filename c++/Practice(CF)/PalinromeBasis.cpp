#include<bits/stdc++.h>
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
const lli N=4e4+10;
const lli M=1e9+7; 

lli dp[N][501];
vll val;
bool checkPalindrome(lli n){
    lli temp=n,reverse=0;
    while(n>0){
        lli rem=n%10;
        reverse=reverse*10+rem;
        n/=10;
    }
    return (reverse==temp);
}

lli func(lli sum,lli indx){
    if(sum==0) return 1;
    if(indx>=val.size() || sum<0) return 0;
    if(dp[sum][indx]!=-1) return dp[sum][indx];

    lli num1=func(sum,indx+1);
    lli num2;
    if(sum-val[indx]>=0) num2=func(sum-val[indx],indx);
    return dp[sum][indx]=(num1+num2)%M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    for(int i=1;i<=40000;i++){
        if(checkPalindrome(i)) val.push_back(i);
    }
    while(t--){
        lli n;
        cin>>n;
        cout<<func(n,0)<<endl;
    }
    return 0;
}