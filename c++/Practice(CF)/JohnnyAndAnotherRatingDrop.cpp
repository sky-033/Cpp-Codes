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
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

vll pow2(64);
void power2(){
    pow2[0]=1;
    pow2[1]=2;
    ff(2,64,1){
        pow2[i]=pow2[i-1]*2;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    power2();
    while(t--){
        lli n;
        cin>>n;
        if(n==1) cout<<1<<endl;
        else if(n==2) cout<<3<<endl;
        else if(n==3) cout<<4<<endl;
        else if(n==4) cout<<7<<endl;
        else{
            lli ans=7;
            lli len=bitlen(n);
            for(lli i=4;i<=len;i++) ans+=i;
            for(lli i=3;i<len;i++){
                lli maxi=i-1;
                lli start=pow2[i-2];
                for(lli j=1;j<=maxi;j++){
                    ans+=(j*start);
                    start/=2;
                }
            }
            for(lli i=0;i<len-1;i++){
                if(n&(1LL<<i)){
                    lli p=i+1;
                    ans+=(pow2[p]-1);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}