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
const lli M=1e9+7; 

vll factors(lli k){
    vll temp;
    for(lli i=1;i*i<=k;i++){
        if(k%i==0){
            temp.push_back(i);
            if((k/i)!=i) temp.push_back(k/i);
        }
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m,k;
    cin>>n>>m>>k;
    vll a(n),b(m),pa(n,0),pb(m,0);
    f(i,n) cin>>a[i];
    f(i,m) cin>>b[i];
    pa[0]=a[0],pb[0]=b[0];
    ff(1,n,1) pa[i]=pa[i-1]+a[i];
    ff(1,m,1) pb[i]=pb[i-1]+b[i];
    vll fact=factors(k);
    sor(fact);
    map<lli,lli> counta,countb;
    fa(fact){
        counta[it]=0,countb[it]=0;
    }
    fa(fact){
        f(i,n){
            if(i+it-1<=n-1 && pa[i+it-1]-(i==0?0:pa[i-1])==it){
                counta[it]++;
            }
        }
        f(i,m){
            if(i+it-1<=m-1 && pb[i+it-1]-(i==0?0:pb[i-1])==it){
                countb[it]++;
            }
        }
    }
    lli ans=0;
    fa(fact){
        lli a1=counta[it],a2=countb[k/it];
        ans+=(a1*a2);
    }
    // fa(counta) cout<<it.first<<" "<<it.second<<endl;
    // fa(countb) cout<<it.first<<" "<<it.second<<endl;
    cout<<ans<<"\n";
    return 0;
}