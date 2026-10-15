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
        lli n,m;
        cin>>n>>m;
        vvll c(n);
        f(i,n){
            c[i].resize(m);
            g(j,m) cin>>c[i][j];
        }
        lli ans=0;
        f(i,m){
            vll temp,prefix(n);
            g(j,n){
                temp.push_back(c[j][i]);
            }
            sor(temp);
            prefix[0]=temp[0];
            for(lli j=1;j<n;j++){
                prefix[j]=prefix[j-1]+temp[j];
            }
            for(lli j=n-1;j>0;j--){
                lli val=temp[j]*j-prefix[j-1];
                ans+=val;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}