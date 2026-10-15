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
        string s;
        cin>>s;
        bool flagp=false,flags=false;
        f(i,n){
            if(s[i]=='p') flagp=true;
            if(s[i]=='s') flags=true;
        }
        if(flags==false || flagp==false){
            cout<<"YES"<<endl;
        }
        else{
            bool flagg=true,flaggg=true;
            ff(1,n,1){
                if(s[i]=='s'){
                    flaggg=false;
                    break;
                }
            }
            ff(0,n-1,1){
                if(s[i]=='p'){
                    flagg=false;
                    break;
                }
            }
            if(flagg==false && flaggg==false) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        
    }
    return 0;
}