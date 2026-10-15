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
        lli k;
        cin>>k;
        vll a(k),hsh(k+1,0);
        f(i,k){
            cin>>a[i];
            hsh[a[i]]++;
        }
        lli val=k-2;
        lli n=-1,m=-1;
        bool flag=false;
        f(i,k){
            if(val%a[k]==0){
                lli check=val/a[k];
                if(a[k]==check){
                    if(hsh[check]>=2){
                        n=check,m=check;
                        flag=true;
                        break;
                    }
                }else{
                    if(hsh[check]>=1){
                        n=check,m=a[k];
                        flag=true;
                        break;
                    }
                }
            }
        }
        cout<<n<<" "<<m<<endl;
    }
    return 0;
}