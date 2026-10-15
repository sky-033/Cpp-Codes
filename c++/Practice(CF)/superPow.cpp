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

lli binExpItr(lli a,lli b, lli M){
    a%=M;
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
    int t;
    cin>>t;
    while(t--){
        lli a;
        cin>>a;
        lli n,m=1337,M=1140;
        cin>>n;
        vll b(n);
        f(i,n) cin>>b[i];
        lli x=0;
        rf(i,n){
            x+=b[i]*binExpItr(10,n-i-1,M);
        }
        lli finalAns=binExpItr(a,x,m);
        cout<<finalAns<<endl;
    }
    return 0;
}