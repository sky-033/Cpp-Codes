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
const lli N=2e5+10;
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
        vll a(n);
        f(i,n) cin>>a[i];
        sor(a);
        if(k>=3) cout<<0<<endl;
        else if(k==1){
            lli mini=1e18;
            f(i,n) mini=min(mini,a[i]);
            f(i,n-1){
                mini=min(mini,a[i+1]-a[i]);
            }
            cout<<mini<<endl;
        }
        else{
            lli ans=1e18;
            f(i,n){
                ans=min(ans,a[i]);
                for(lli j=i+1;j<n;j++){
                    lli diff=a[j]-a[i];
                    ans=min(ans,diff);
                    lli it=lower_bound(all(a),diff)-a.begin();
                    if(it<n) ans=min(ans,abs(a[it]-diff));
                    if(it>0) ans=min(ans,abs(a[it-1]-diff));
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}