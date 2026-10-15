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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,x,y;
        cin>>n>>x>>y;
        lli ans=0;
        if(x==y){
            ans=0;
        }
        else {
            lli gcd=__gcd(x,y);
            lli lcm=(x*y)/gcd;
            lli a1=n/x,a2=n/lcm,a3=n/y;
            lli add=a1-a2;
            lli m=n-add;
            lli sum=(n*(n+1))/2-(m*(m+1))/2;
            ans+=sum;
            lli moreadd=a3-a2;
            ans-=(moreadd*(moreadd+1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}