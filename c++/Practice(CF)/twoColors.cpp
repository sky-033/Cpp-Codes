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
        lli n,m;
        cin>>n>>m;
        vll a(m);
        f(i,m){
            cin>>a[i];
            if(a[i]>=n) a[i]=n-1;
        }
        lli ans=0;
        sort(a.begin(),a.end());
        vll suffix(m);
        suffix[m-1]=a[m-1];
        fb(m-1,0,1){
            suffix[i]=suffix[i+1]+a[i];
        }
        ff(0,m-1,1){
            lli val=n-a[i];
            lli low=lower_bound(a.begin()+i+1,a.end(),val)-a.begin();
            lli len=m-low;
            if(low!=m) ans+=2*(suffix[low]+len-len*val);
        }
        cout<<ans<<endl;
    }
    return 0;
}