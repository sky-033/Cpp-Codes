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
        lli n,l,r,k;
        cin>>n>>l>>r>>k;
        if(n==2) cout<<-1<<endl;
        else if(n&1) cout<<l<<endl;
        else{
            lli a1=64-__builtin_clzll(l);
            lli a2=64-__builtin_clzll(r);
            if(a1==a2) cout<<-1<<endl;
            else{
                lli ans1=l,ans2=r;
                lli mid;
                while(r-l>1){
                    mid=(l+r)/2;
                    if(64-__builtin_clzll(mid)>=(a1+1)) r=mid;
                    else l=mid+1;
                }
                if((64-__builtin_clzll(l))>=(a1+1)) ans2=l;
                else ans2=r;
                if(k<=n-2) cout<<ans1<<endl;
                else cout<<ans2<<endl;
            }
        }
    }
    return 0;
}