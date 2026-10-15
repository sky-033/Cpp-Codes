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
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    vll lis;
    vll inserted(n,-1);
    f(i,n){
        lli it=a[i];
        auto itt=lower_bound(all(lis),it);
        if(itt==lis.end()){
            lis.push_back(it);
            inserted[i]=lis.size();
        }
        else{
            *itt=it;
            inserted[i]=itt-lis.begin()+1;
        }
    }
    cout<<lis.size()<<endl;
    lli cur=lis.size();
    vll lis_ele;
    for(lli i=n-1;i>=0;i--){
        if(inserted[i]==cur){
            lis_ele.push_back(a[i]);
            cur--;
        }
    }
    reverse(all(lis_ele));
    fa(lis_ele) cout<<it<<" ";
    return 0;
}