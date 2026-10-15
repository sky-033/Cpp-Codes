#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vpw vector<pair<lli,lli>>
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
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n),b(n);
        f(i,n) cin>>a[i];
        lli temp=a[0];
        f(i,n){
            if(a[i]>=temp){
                temp=a[i];
                b[i]=temp;
            }
            else b[i]=temp;
        }
        lli x=0;
        lli D=0;
        f(i,n){
            D=max(D,b[i]-a[i]);
        }
        lli val=0;
        while(val<D){
            val+=(1LL<<x);
            x++;
        }
        cout<<x<<endl;
    }
    return 0;
}