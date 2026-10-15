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
        vll a(n),b(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        vll diff(n);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        f(i,n){
            lli indx=upper_bound(a.begin(),a.end(),b[i])-a.begin();
            diff[i]=n-indx;
        }f(i,n) diff[i]-=(n-i-1);
        lli ans=1;
        f(i,n){
            ans=(ans*diff[i])%M;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}