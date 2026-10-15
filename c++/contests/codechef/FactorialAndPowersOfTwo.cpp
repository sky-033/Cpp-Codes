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
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

vll fact(15),pow2(40);
void factorial(){
    fact[0]=1;
    ff(1,15,1) fact[i]=i*fact[i-1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    factorial();
    while(t--){
        lli n;
        cin>>n;
        lli ans=1e18;
        for(lli mask=0;mask<(1<<15);mask++){
            lli factSum=0,cnt=0;
            for(lli i=0;i<15;i++){
                if(mask&(1<<i)){
                    factSum+=fact[i];
                    cnt++;
                }
            }
            if(factSum>n) continue;
            lli rem=n-factSum;
            cnt+=setbits(rem);
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}