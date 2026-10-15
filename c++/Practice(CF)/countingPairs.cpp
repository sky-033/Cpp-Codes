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
        lli n,x,y;
        cin>>n>>x>>y;
        vll a(n);
        lli sum=0;
        f(i,n){
            cin>>a[i];
            sum+=a[i];
        }
        lli miniSum=sum-y;
        lli maxiSum=sum-x;
        lli ans=0;
        sort(a.begin(),a.end());
        f(i,n-1){
            lli mini=miniSum-a[i];
            lli maxi=maxiSum-a[i];
            lli low=lower_bound(a.begin()+i+1,a.end(),mini)-a.begin();
            lli high=upper_bound(a.begin()+i+1,a.end(),maxi)-a.begin();
            ans+=(high-low);
        }
        cout<<ans<<endl;
    }
    return 0;
}