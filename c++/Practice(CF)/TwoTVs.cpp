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
    lli n;
    cin>>n;
    vp try1;
    f(i,n){
        lli l,r;
        cin>>l>>r;
        try1.push_back({l,-1});
        try1.push_back({r,1});
    }
    sor(try1);
    lli ct=0;
    bool flag=true;
    fa(try1){
        ct=ct+(-1)*it.second;
        if(ct>2){
            flag=false;
            break;
        }
    }
    cout<<(flag?"YES":"NO")<<endl;
    return 0;
}