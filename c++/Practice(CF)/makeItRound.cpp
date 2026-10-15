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
        lli n,m;
        cin>>n>>m;
        lli n1=n,n2=n;
        lli ct2=0,ct5=0;
        lli val=1;
        while(n>0 && n%2==0){
            ct2++;
            n/=2;
        }
        while(n>0 && n%5==0){
            ct5++;
            n/=5;
        }
        if(ct2>ct5){
            while(val*5<=m){
                val*=5;
                ct5++;
                if(ct2==ct5) break;
            }
        }
        else if(ct2<ct5){
            while(val*2<=m){
                val*=2;
                ct2++;
                if(ct2==ct5) break;
            }
        }
        while(val*10<=m) val*=10;
        n1*=val;
        lli id=1;
        for(lli i=1;i<=9;i++){
            if(n1*i<=n2*m){
                id=i;
            }
            else break;
        }
        cout<<n1*id<<endl;
    }
    return 0;
}