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
        vvll mat(n);
        f(i,n){
            mat[i].resize(n);
            g(j,n){
                cin>>mat[i][j];
            }
        }
        lli ans=0;
        for(lli d=-(n-1);d<=(n-1);d++){  
            vll b;
            lli i0=max(0LL,-d),i1=min(n-1,n-1-d);
            for(lli i=i0;i<=i1;i++){
                lli j=i+d;
                lli need=max(0LL,-mat[i][j]);
                b.push_back(need);
            }
            
            lli maxi=0;
            fa(b){
               maxi=max(maxi,it);
            }
            ans+=maxi;
        }
        cout<<ans<<endl;
    }
    return 0;
}