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
const lli N=2e5+10;

vll hsh(N);
vll multiples_ct(N);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    f(i,n){
        lli x;
        cin>>x;
        hsh[x]++;
    }
    for(lli i=1;i<N;i++){
        for(lli j=i;j<N;j+=i){
            multiples_ct[i]+=hsh[j]; // i ka multiple j hoga aur j jitna baar given array me hoga utna multiples[i] me add krte jao
        }
    }
    lli t;
    cin>>t;
    while(t--){
        lli p,q;
        cin>>p>>q;
        lli ans=multiples_ct[p]+multiples_ct[q];
        lli lcm=(p*q)/__gcd(p,q);
        if(lcm<N) ans-=multiples_ct[lcm];
        cout<<ans<<endl;
    }
    return 0;
}