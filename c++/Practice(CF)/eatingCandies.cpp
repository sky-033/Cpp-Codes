#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll w(n);
        f(i,n) cin>>w[i];
        vll prefix_sum(n),suffix_sum(n);
        prefix_sum[0]=w[0];
        suffix_sum[n-1]=w[n-1];
        ff(1,n,1) prefix_sum[i]=prefix_sum[i-1]+w[i];
        fb(n-1,0,1) suffix_sum[i]=suffix_sum[i+1]+w[i];
        reverse(suffix_sum.begin(),suffix_sum.end());
        lli maxi=0;
        f(i,n){
            lli find=lower_bound(suffix_sum.begin(),suffix_sum.end(),prefix_sum[i])-suffix_sum.begin();
            if(suffix_sum[find]==prefix_sum[i] && (i+1+find+1)<=n){
                maxi=max(maxi,i+find+2);
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}