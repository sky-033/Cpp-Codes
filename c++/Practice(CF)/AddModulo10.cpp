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
        vll a(n);
        f(i,n) cin>>a[i];
        sor(a);
        bool flag=true;
        while(true){
            if(a[n-1]%10==6 || a[n-1]%10==0) break;
            a[n-1]+=(a[n-1]%10);
        }
        f(i,n-1){
            flag=true;
            while(a[i]<a[n-1]){
                lli rem=a[i]%10;
                if(rem!=6) a[i]+=rem;
                else{
                    lli times=(a[n-1]-a[i])/20;
                    a[i]+=times*20;
                    if(a[i]<a[n-1]) a[i]+=(a[i]%10);
                }
                if(a[i]%10==0 && a[i]!=a[n-1]){
                    flag=false;
                    break;
                }
            }
            if(a[i]!=a[n-1]){
                flag=false;
                break;
            }
            if(!flag) break;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}