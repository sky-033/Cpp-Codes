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
        f(i,n) cin>>a[i];
        lli l=0,h=n-1;
        lli sum=0,sum1=0;
        bool flag=true;    //Y-win
        if(a[0]<0 || a[n-1]<0) flag=false;    //Y-lose
        else{
            while(l<n){
                if(a[l]>0){
                    sum+=a[l];
                    l++;
                }
                else{
                    if(sum<=abs(a[l])){
                        flag=false;            //Y-lose
                        break;
                    }
                    else{
                        sum+=a[l];
                        l++;
                    }
                }
            }
            while(h>=0){
                if(a[h]>0){
                    sum1+=a[h];
                    h--;
                }
                else{
                    if(sum1<=abs(a[h])){
                        flag=false;    //Y-lose
                        break;
                    }
                    else{
                        sum1+=a[h];
                        h--;
                    }
                }
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
   return 0;
}