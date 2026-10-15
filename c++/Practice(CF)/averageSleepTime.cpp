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
    
        lli n,k;
        cin>>n>>k;
        lli left=k;
        lli right=n-k+1;
        vll a(n+1,0);
        ff(1,n+1,1){
            lli x;
            cin>>x;
            a[i]=x;
        }
        lli val=0;
        for(lli i=1;i<=n/2;i++){
            if(k<=n/2){
                val+=min(i*a[i],k*a[i]);
            }
            else{
                val+=min(i*a[i],(n-k+1)*a[i]);
            }
        }
        for(lli i=n/2+1;i<=n;i++){
            if(k<=n/2){
                val+=min((n-i+1)*a[i],k*a[i]);
            }
            else{
                val+=min((n-i+1)*a[i],(n-k+1)*a[i]);
            }
        }
        double avg=(double)val/(n-k+1);
        cout<<fixed<<setprecision(6)<<avg<<endl;
    
    return 0;
}