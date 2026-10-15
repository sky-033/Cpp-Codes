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
        lli n,q;
        cin>>n>>q;
        vll a(n);
        f(i,n) cin>>a[i];
        lli val=0;
        vll minii(n+1,0);
        for(lli j=0;j<n-1;j++){
            val+=min(a[j],a[j+1]);
        }
        if(n==1){
            lli indx,x;
            cin>>indx>>x;
            cout<<0<<endl;
        }
        else{
f(i,q){
            lli indx,x;
            cin>>indx>>x;
            lli temp=a[indx-1];
            if(indx==1){
                lli temp1=a[indx];
                lli mini=min(temp,temp1);
                lli minic=min(temp1,x);
                val=val-mini+minic;
            }
            else if(indx==n){
                lli temp1=a[indx-2];
                lli mini=min(temp,temp1);
                lli minic=min(temp1,x);
                val=val-mini+minic;
            }
            else{
                lli temp1=a[indx];
                lli temp2=a[indx-2];
                lli minip1=min(temp1,temp);
                lli minip2=min(temp2,temp);
                lli mini1=min(x,temp1);
                lli mini2=min(x,temp2);
                val=val-minip1+mini1;
                val=val-minip2+mini2;
            }
            a[indx-1]=x;
            cout<<val<<endl;
        }
        }
        
    }
    return 0;
}