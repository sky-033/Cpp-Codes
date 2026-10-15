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
        lli n,h;
        cin>>n>>h;
        vll a(n+1);
        ff(1,n+1,1) cin>>a[i];
        lli ans=0;
        ff(1,n+1,1){
            lli H=h;
            vll temp;
            for(lli j=1;j<=i;j++){
                temp.push_back(a[j]);
            }
            sor(temp);
            reverse(all(temp));
            // fa(temp) cout<<it<<" ";
            // cout<<endl;
            for(lli j=0;j<temp.size();j+=2){
                lli maxi=temp[j];
                H-=maxi;
            }
            // cout<<H<<" ";
            if(H>=0) ans=max(ans,i);
            else break;
        }
        cout<<ans<<endl;
    
    return 0;
}