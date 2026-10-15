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
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
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
        vll a(n),prefixXor(n),suffixXor(n);
        f(i,n) cin>>a[i];
        prefixXor[0]=a[0],suffixXor[n-1]=a[n-1];
        ff(1,n,1) prefixXor[i]=prefixXor[i-1]^a[i];
        for(lli i=n-2;i>=0;i--) suffixXor[i]=suffixXor[i+1]^a[i];
        bool flag=false,flag2=false,flag3=false;
        f(i,n){
            lli val=0;
            lli indx=-1;
            flag=false,flag2=false;
            lli pre=prefixXor[i];
            for(int j=n-1;j>i;j--){
                if(pre==suffixXor[j]){
                    indx=j;
                    flag=true;
                    break;
                }
            }
            if(flag){
                for(int k=i+1;k<indx;k++){
                    val^=a[k];
                }
                if(val==0 || val==pre) flag2=true;
            }
            if(flag && flag2){
                flag3=true;
                break;
            }
        }
        if(flag3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}