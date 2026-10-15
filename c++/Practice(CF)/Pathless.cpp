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
        lli n,s,sum=0;
        cin>>n>>s;
        vll a(n);
        f(i,n) cin>>a[i];
        sum=accumulate(all(a),0);
        if(sum>s){
            fa(a) cout<<it<<" ";
            cout<<endl;
        }
        else if(sum==s) cout<<-1<<endl;
        else if(s-sum==1){
            lli ct0=0,ct1=0,ct2=0;
            f(i,n){
                if(a[i]==0) ct0++;
                else if(a[i]==1) ct1++;
                else ct2++;
            }
            f(i,ct0) cout<<0<<" ";
            f(i,ct2) cout<<2<<" ";
            f(i,ct1) cout<<1<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}