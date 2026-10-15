#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
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
        bool flag=false;
        f(i,n){
            if(a[i]>=0){
                flag=true;
                break;
            }
        }
        lli ans=-1e9,sum=0;
        if(a[0]>=0){
            sum+=a[0];
            ans=sum;
        }
        lli l=0,h=1;
        while(h<n){
            if(abs(a[h])%2!=abs(a[h-1])%2 &&  sum+a[h]>=0){
                sum+=a[h];
            }
            else{
                l=h;
                if(a[l]>=0) sum=a[l];
                else sum=0;
            }
            ans=max(sum,ans);
            h++;
        }
        if(flag==false){
            sort(a.begin(),a.end());
            ans=a[n-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}