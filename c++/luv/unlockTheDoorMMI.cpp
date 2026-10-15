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
const lli N=1e5+10;
vll fact(N);

void factorial(){
    fact[0]=1;
    ff(1,N,1) fact[i]=(i*fact[i-1])%M;
}

lli binExpItr(lli a, lli b){
    lli ans=1;
    while(b>0){
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorial();
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k; // n is lenth of password,k is total alphabet
        lli num=fact[k];
        lli den=fact[k-n];
        lli ans=(num*binExpItr(den,M-2))%M;
        cout<<ans<<endl;
    }
    return 0;
}