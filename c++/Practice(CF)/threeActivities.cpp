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
        vvll a(n),b(n),c(n);
        f(i,n){
            lli a1;
            cin>>a1;
            a[i]={a1,i};
            
        }
        f(i,n){
            lli b1;
            cin>>b1;
            b[i]={b1,i};
            
        }
        f(i,n){
           lli c1;
           cin>>c1;
           c[i]={c1,i};
        }
        rsor(a),rsor(b),rsor(c);
        f(i,n) cout<<a[i][0]<<" "<<a[i][1]<<endl;
        lli ans=0;
        f(i,3){
            g(j,3){
                h(k,3){
                    if(a[i][1]!=b[j][1] && b[j][1]!=c[k][1] && a[i][1]!=c[k][1]){
                        ans=max(ans,a[i][0]+b[j][0]+c[k][0]);
                    }
                }
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}