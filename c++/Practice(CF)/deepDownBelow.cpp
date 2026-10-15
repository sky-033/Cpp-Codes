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
        lli n;
        cin>>n;
        vll bin;
        f(i,n){
            lli k;
            cin>>k;
            vll a(k);
            g(j,k) cin>>a[j];
            lli maxi=-1;
            g(j,k){
                maxi=max(maxi,a[j]);
                a[j]=maxi; 
            }
            lli val=a[0]+1;
            for(lli j=k-1;j>0;j--){
                if(a[j]!=a[j-1]){
                    val=max(val,a[j]-j+1);
                }
            }
            g(j,k) a[j]=val;
            g(j,k) bin.push_back(val);
        }
        sor(bin);
        lli ans=bin[0];
        lli size=bin.size();
        for(lli i=size-1;i>0;i--){
            if(bin[i]!=bin[i-1]){
                ans=max(ans,bin[i]-i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}