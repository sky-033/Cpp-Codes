#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vpw vector<pair<lli,lli>>
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
        lli n,x,y;
        cin>>n>>x>>y;
        vll a(n);
        f(i,n) cin>>a[i];
        if(x%2){
            //Alice--->Odd
            lli val=1;
            f(i,n){
                if(val==0 && a[i]%2) val=1;
                else if(val==1 && a[i]%2) val=0;
            }
            if((val%2 && y%2) || (!(val%2) && !(y%2))) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else{
            //Alice--->Even
            lli val=0;
            f(i,n){
                if(val==0 && a[i]%2) val=1;
                else if(val==1 && a[i]%2) val=0;
            }
            if((val%2 && y%2) || (!(val%2) && !(y%2))) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
    }
    return 0;
}