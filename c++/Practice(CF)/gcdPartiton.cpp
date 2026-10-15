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
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        vll prefix(n-1),suffix(n-1);
        prefix[0]=a[0];
        ff(1,n-1,1){
            prefix[i]=prefix[i-1]+a[i];
        }
        suffix[n-2]=a[n-1];
        fb(n-2,0,1){
            suffix[i]=suffix[i+1]+a[i+1];
        }
        lli ans=__gcd(prefix[0],suffix[0]);
        ff(1,n-1,1){
            ans=max(ans,__gcd(prefix[i],suffix[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}