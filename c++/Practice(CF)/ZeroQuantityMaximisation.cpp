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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<pair<lli,lli>,lli> mp1;
    lli n;
    cin>>n;
    vll a(n),b(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>b[i];
    lli ct=0,times=0;
    f(i,n){
        if(a[i]==0 && b[i]==0) ct++;
        if(b[i]==0 && a[i]!=0) times++;
    }
    f(i,n){
        if(a[i]!=0 && b[i]!=0){
            lli gcd=__gcd(abs(a[i]),abs(b[i]));
            if(a[i]>0) b[i]=-1*b[i];
            if(a[i]<0){
                a[i]=-1*a[i];
                b[i]=-1*b[i];
            }
            mp1[{b[i]/gcd,a[i]/gcd}]++;
        }
    }
    lli maxi=times+ct;
    // cout<<times<<endl;
    fa(mp1){
        it.second+=ct;
        maxi=max(maxi,it.second);
        // cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    }
    cout<<maxi<<endl;
    return 0;
}