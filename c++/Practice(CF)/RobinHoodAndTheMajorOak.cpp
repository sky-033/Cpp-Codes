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
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        lli start=n-k+1;
        lli end=n;
        lli ctodd=0,cteven=0;
        if(start%2==0 && end%2==0){
            lli len=end-start+1;
            cteven=len/2+1;
            ctodd=len/2;
        }
        else if(start%2==0 && end%2!=0 || start%2!=0 && end%2==0){
            lli len=end-start+1;
            cteven=len/2;
            ctodd=len/2;
        }
        else{
            lli len=end-start+1;
            cteven=len/2;
            ctodd=len/2+1;
        }
        if(ctodd%2!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}