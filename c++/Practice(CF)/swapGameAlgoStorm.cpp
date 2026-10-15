#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
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
        lli n,m,k,sum=0;
        cin>>n>>m>>k;
        vll a(n),b(m);
        f(i,n){
            cin>>a[i];
            sum+=a[i];
        }
        f(i,m) cin>>b[i];
        sort(a.begin(),a.end()),sort(b.begin(),b.end());
        if(k&1){
            if(a[0]<b[m-1]) sum+=(b[m-1]-a[0]);
        }
        else{
            if(a[0]<b[m-1]){
                sum+=(b[m-1]-a[0]);
                lli temp=a[0];
                a[0]=b[m-1];
                b[m-1]=temp;
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                sum+=(b[0]-a[n-1]);
            }
            else{
                sum+=(b[0]-a[n-1]);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}