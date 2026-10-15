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
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        vll prefix_sum(n,0),suffix_sum(n,0);
        if(a[0]>0) prefix_sum[0]=a[0];
        if(a[n-1]<0) suffix_sum[n-1]=-a[n-1];
        ff(1,n,1){
            prefix_sum[i]=prefix_sum[i-1];
            if(a[i]>0) prefix_sum[i]+=a[i];
        }
        fb(n-1,0,1){
            suffix_sum[i]=suffix_sum[i+1];
            if(a[i]<0) suffix_sum[i]-=a[i];
        }
        lli maxi=-1e18;
        f(i,n){
            maxi=max(maxi,prefix_sum[i]+suffix_sum[i]);
        }
        cout<<maxi<<endl;
    }
    return 0;
}