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

lli find(lli z,lli x,lli val){
    lli cost=1e18;
    for(lli i=1;i*i<=val;i++){
        if(val%i==0){
            cost=min(cost,abs(z-x*i));
            cost=min(cost,abs(z-x*val/i));
        }
    }
    return cost;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli x,y,z,c;
        cin>>x>>y>>z>>c;
        if(x==y) cout<<0<<endl;
        else{
            lli ans=2*c;                         //itna max ans hoga
            if(x>y) swap(x,y);
            if(y%x==0){                          //agar koi ek factor hai toh
                lli val=y/x;
                lli cost=find(z,x,val);          //min z se kitna minus karenge ki lcm(z,x)==gcd(z,y)!
                ans=min(ans,c+cost);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}