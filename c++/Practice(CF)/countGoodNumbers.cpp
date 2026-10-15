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
        lli l,r;
        cin>>l>>r;
        lli total=0;
        total+=(r/2-(l-1)/2);
        total+=(r/3-(l-1)/3);
        total+=(r/5-(l-1)/5);
        total+=(r/7-(l-1)/7);
        total-=(r/6-(l-1)/6);
        total-=(r/10-(l-1)/10);
        total-=(r/14-(l-1)/14);
        total-=(r/15-(l-1)/15);
        total-=(r/21-(l-1)/21);
        total-=(r/35-(l-1)/35);
        total+=(r/30-(l-1)/30);
        total+=(r/42-(l-1)/42);
        total+=(r/70-(l-1)/70);
        total+=(r/105-(l-1)/105);
        total-=(r/210-(l-1)/210);
        cout<<(r-l+1)-total<<endl;
    }
    return 0;
}