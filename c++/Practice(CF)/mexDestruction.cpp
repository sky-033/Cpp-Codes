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
        vll a(n);
        f(i,n) cin>>a[i];
        if(n==1){
            if(a[0]==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else if(n==2){
            if(a[0]==0 && a[1]==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else{
            bool flag=false;
            lli indx1=0,indx2=n-1;
            f(i,n){
                if(a[i]!=0) indx1=i;
            }
            rf(i,n){
                if(a[i]!=0) indx2=i;
            }
            for(lli i=indx1;i<=indx2;i++){
                if(a[i]==0){
                    flag=true;
                    break;
                }
            }
            bool flag1=true;
            f(i,n){
                if(a[i]!=0){
                    flag1=false;
                    break;
                }
            }
            if(flag1) cout<<0<<endl;
            else if(flag) cout<<2<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}