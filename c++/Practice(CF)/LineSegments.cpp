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
        lli n;
        cin>>n;
        lli px,py,qx,qy;
        cin>>px>>py>>qx>>qy;
        vll a(n);
        lli sum=0;
        lli maxi=-1;
        f(i,n){
            cin>>a[i];
            sum+=a[i];
            maxi=max(maxi,a[i]);
        }
        lli x1=abs(qx-px),x2=abs(qy-py);
        x1*=x1,x2*=x2;
        x1+=x2;
        lli D_min=max(0LL,sum-2*maxi);
        lli D_max=sum;
        if(x1>=D_min*D_min && x1<=D_max*D_max) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}