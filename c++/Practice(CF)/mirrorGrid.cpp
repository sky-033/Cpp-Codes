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
        vector<string> grid(n);
        f(i,n){
            string s;
            cin>>s;
            grid[i]=s;
        }
        lli l=n-1,i=0,ans=0,start=0;
        while(l-start>0){
            for(lli j=start;j<l;j++){
                lli ct0=0,ct1=0;
                if(grid[i][j]=='0') ct0++;
                else ct1++;
                if(grid[j][n-i-1]=='0') ct0++;
                else ct1++;
                if(grid[n-1-i][n-1-j]=='0') ct0++;
                else ct1++;
                if(grid[n-1-j][i]=='0') ct0++;
                else ct1++;
                ans+=min(4-ct1,4-ct0);
                
            }
            i++;
            l--;
            start++;
        }
        cout<<ans<<endl;
    }
    return 0;
}