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
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n),b(n),prefix_sum(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        prefix_sum[0]=a[0];
        ff(1,n,1) prefix_sum[i]=prefix_sum[i-1]+a[i];
        lli lastmax=b[0],sum=0;
        f(i,min(n,k)){
            lastmax=max(lastmax,b[i]);
            sum=max(sum,prefix_sum[i]+(k-i-1)*lastmax);
        }
        cout<<sum<<endl;
    }
    return 0;
}