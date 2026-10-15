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
        f(i,n){
            cin>>a[i];
            a[i]=k-a[i]%k;
        }
        sor(a);
        map<lli,lli> hsh;
        lli maxi=-1,ele=-1;
        f(i,n){
            if(a[i]!=0) hsh[a[i]]++;
        }
        fa(hsh){
            if(maxi<=it.second){
                maxi=it.second;
                ele=it.first;
            }
        }
        // fa(hsh) cout<<it.first<<" "<<it.second<<endl;
        lli ans=(maxi-1)*k;
        ans+=ele+1;
        cout<<ans<<endl;
    }
    return 0;
}