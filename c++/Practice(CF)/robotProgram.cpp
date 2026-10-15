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
        lli n,x,k;
        cin>>n>>x>>k;
        string s;
        cin>>s;
        lli ans=0;
        if(x==0) ans=0;
        else{
            ans++;
            f(i,n){
                if(s[i]=='L') x--;
                else x++;
                if(x==0){
                    k=k-(i+1);
                }
            }
        }
        if(k<0) cout<<0<<endl;
        else{
            lli sum=0,mini=1e9;
            f(i,n){
                if(s[i]=='L') sum--;
                else sum++;
                if(sum==0){
                    mini=i+1;
                    break;
                }
            }
            if(mini!=1e9)ans+=k/mini;
            cout<<ans<<endl;
        }
    }
    return 0;
}