#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=998244353; 
vll fact,ifact;
lli binExpItr(lli a,lli b){
    lli ans=1;
    a%=M;
    while(b>0){
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

lli Combi(lli n,lli k){
    return ((fact[n]*ifact[k])%M*ifact[n-k])%M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    fact.resize(n+1),ifact.resize(n+1);
    fact[0]=1;
    ff(1,n+1,1) fact[i]=fact[i-1]*i%M;
    ifact[n]=binExpItr(fact[n],M-2);
    for(lli i=n;i>=1;i--) ifact[i-1]=ifact[i]*i%M;
    lli ans=Combi(n/3,n/6);
    for(lli i=0;i<n;i+=3){
        map<lli,lli> temp;
        for(lli j=i;j<i+3;j++){
            temp[a[j]]++;
        }
        if(temp.size()==1) ans=(ans*3)%M;
        if(temp.size()==2){
            fa(temp){
                if(it.second==2){
                    ans=(ans*2)%M;
                }
                break;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}