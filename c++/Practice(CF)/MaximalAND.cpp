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
        vll a(n);
        f(i,n) cin>>a[i];
        vll hsh(31);
        f(i,n){
            for(lli j=0;j<31;j++){
                if(a[i]&(i<<j)) hsh[j]++;
            }
        }
        lli ans=0;
        if(k>=n){
            rf(i,31){
                lli add=n-hsh[i];
                hsh[i]+=add;
                k-=add;
                if(k<n) break;
            }
            rf(i,31){
                lli add=n-hsh[i];
                if(add<=k){
                    hsh[i]+=add;
                    k-=add;
                }
                if(k<=0) break;
            }
            rf(i,31){
                if(hsh[i]==n){
                    ans+=pow(2,i);
                }
            }
        }
        else{
            rf(i,31){
                lli add=n-hsh[i];
                if(add<=k){
                    hsh[i]+=add;
                    k-=add;
                }
                if(k<=0) break;
            }
            rf(i,31){
                if(hsh[i]==n){
                    ans+=pow(2,i);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}