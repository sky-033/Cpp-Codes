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
        char c;
        cin>>c;
        string s;
        cin>>s;
        bool flag=true;
        f(i,n){
            if(s[i]!=c){
                flag=false;
                break;
            }
        }
        if(flag) cout<<0<<endl;
        else{
            lli val=-1;
            for(lli i=1;i<=n;i++){
                flag=true;
                for(lli j=i;j<=n;j+=i){
                    if(s[j-1]!=c){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    val=i;
                    break;
                }
            }
            if(flag){
                cout<<1<<endl;
                cout<<val<<endl;
            }
            else{
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
            }
        }
        
    }
    return 0;
}