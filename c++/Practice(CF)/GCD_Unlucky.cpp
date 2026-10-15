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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll pre(n),suf(n);
        f(i,n) cin>>pre[i];
        f(i,n) cin>>suf[i];
        bool flag=true;
        ff(0,n-1,1){
            if(pre[i]%pre[i+1]!=0){
                flag=false;
                break;
            }
            if(suf[i+1]%suf[i]!=0){
                flag=false;
                break;
            }
            if(__gcd(pre[i],suf[i+1])!=suf[0]){
                flag=false;
                break;
            }
        }
        if(suf[0]!=pre[n-1]) flag=false;
        
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}