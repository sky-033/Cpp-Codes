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
#define sor(x) sort(all(x))
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
        lli sum=0;
        f(i,n){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%3==0) cout<<"NO"<<endl;
        else{
            vll prefix(n);
            prefix[0]=a[0];
            ff(1,n,1) prefix[i]=prefix[i-1]+a[i];
            lli last=0,a1=-1,a2=-1;
            f(i,n){
                if(prefix[i]%3==0) last=i+1;    //last occurence of rem=0
                else if(prefix[i]%3==1){
                    if(a1==-1) a1=i+1;          //first occurence of rem=1
                }
                else{
                    if(a2==-1) a2=i+1;          //first occurence of rem=2
                }
            }
            bool flag=false;
            if(a1>=last) flag=true;            //last occurence of rem=1,2 agar last se bada hai toh pura reverse kardo a1 ya a2 jo bada hai waha tak
            if(a2>=last) flag=true;
            cout<<(flag?"YES":"NO")<<endl;
            
            
        }
    }
    return 0;
}