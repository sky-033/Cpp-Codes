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
        lli n,k;
        cin>>n>>k;
        vll a(n),b(n);
        f(i,n){
            cin>>a[i];
            a[i]%=k;
        }
        f(i,n){
            cin>>b[i];
            b[i]%=k;
        }
        multiset<lli> B;
        fa(b) B.insert(it);
        bool flag=true;
        fa(a){
            lli val1=it,val2;
            val2=k-val1;
            if(B.find(val1)!=B.end()){
                B.erase(B.find(val1));
            }
            else if(B.find(val2)!=B.end()){
                B.erase(B.find(val2));
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}