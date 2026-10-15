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
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli a,b;
        cin>>a>>b;
        lli ans=a;
        lli xor1;
        lli rem=(a-1)%4;
        if(rem==0) xor1=a-1;
        else if(rem==1) xor1=1;
        else if(rem==2) xor1=a;
        else if(rem==3) xor1=0;
        if(xor1!=b){
            lli x=xor1^b;
            if(x==a) ans+=2;
            else ans++;
        }  
        cout<<ans<<endl;
    }
    return 0;
}