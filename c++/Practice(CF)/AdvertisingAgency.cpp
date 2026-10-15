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
const lli N=1001;
const lli M=1e9+7; 

vll fact(N),invFact(N);

lli binExpItr(lli a,lli b){
    lli ans=1;
    a=a%M;
    while(b>0){
        if(b&1) ans=(ans*a)%M;
        b>>=1;
        a=(a*a)%M;
    }
    return ans;
}

void precompute(){
    fact[0]=1;
    ff(1,1001,1) fact[i]=(fact[i-1]*i)%M;
    invFact[1000]=binExpItr(fact[1000],M-2);
    for(lli i=999;i>=0;i--) invFact[i]=(invFact[i+1]*(i+1))%M;
}

lli nCr(lli n,lli r){
    return (((fact[n]*invFact[r])%M)*invFact[n-r])%M;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    precompute();
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n);
        f(i,n) cin>>a[i];
        sor(a);
        reverse(all(a));
        vll ans;
        set<lli> st;
        f(i,k){
            ans.push_back(a[i]);
            st.insert(a[i]);
        }
        ff(k,n,1){
            if(st.find(a[i])!=st.end()) ans.push_back(a[i]);
        }
        sor(ans);
        lli t=ans.size();
        lli val=ans[0],ct=0;
        fa(ans){
            if(it==val) ct++;
        }
        k-=(t-(ct));
        cout<<nCr(ct,k)<<"\n";
    }
    return 0;
}