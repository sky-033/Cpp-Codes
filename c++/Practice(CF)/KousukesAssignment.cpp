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
        lli ans=0;
        vll prefix(n);
        prefix[0]=a[0];
        ff(1,n,1) prefix[i]=prefix[i-1]+a[i];
        lli l=0,h=0;
        unordered_map<lli,lli> hsh;
        while(h<n){
            if(prefix[h]!=0){
                hsh[prefix[h]]++;
                if(hsh[prefix[h]]==2){
                    ans++;
                    hsh[prefix[h]]=0;
                }
            }
            else if(prefix[h]==0){
                hsh.clear();
            }
            if(prefix[h]==0) ans++;
            h++;
        }
        cout<<ans<<endl;
    }
    return 0;
}