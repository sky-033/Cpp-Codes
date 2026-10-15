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
        lli n,x;
        cin>>n>>x;
        vll a(n),b(n),c(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        f(i,n) cin>>c[i];
        lli ans=0;
        lli size=log2(x)+1;
        f(i,n){
            bool flag=true;
            g(j,32){
                if(!(x&(1<<j)) && a[i]&(1<<j)){
                    flag=false;
                    break;
                }
            }
            if(flag) ans|=a[i];
            else break;
        }
        
        f(i,n){
            bool flagb=true;
            g(j,32){
                if(!(x&(1<<j)) && b[i]&(1<<j)){
                    flagb=false;
                    break;
                }
            }
            if(flagb) ans|=b[i];
            else break;
        }
        
        f(i,n){
            bool flagc=true;
            g(j,32){
             
                if(!(x&(1<<j)) && c[i]&(1<<j)){
                    flagc=false;
                    break;
                }
            }
           
            if(flagc) ans|=c[i];
            else break;
        }
        
    
        if(ans==x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}