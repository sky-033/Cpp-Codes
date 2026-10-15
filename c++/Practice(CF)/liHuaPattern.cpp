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
        vvll a(n),b(n);
        f(i,n){
            a[i].resize(n);
            g(j,n){
                cin>>a[i][j];
            }
        }
        f(i,n){
            b[i].resize(n);
            g(j,n){
                b[i][j]=a[n-i-1][n-j-1];
            }
        }    
        lli ct=0;
        if(n&1){
            f(i,n/2){
                g(j,n){
                    if(a[i][j]!=b[i][j]) ct++;
                }
            }
            lli ctt=0;
            f(i,n){
                if(a[n/2][i]!=b[n/2][i]) ctt++;
            }
            ctt>>=1;
            ct+=ctt;
            k-=ct;
            if(k<0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else{
            f(i,n/2){
                g(j,n){
                    if(a[i][j]!=b[i][j]) ct++;
                }
            } 
            k-=ct;
            if(k<0 || k&1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }    
    }
    return 0;
}