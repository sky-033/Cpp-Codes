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
vll one_step(vll& a) {
    lli n=(lli)a.size();
    vll cnt(n + 2, 0);
    fa(a) if(0<=it && it<=n) cnt[it]++;
    lli mex=0;
    while(cnt[mex]>0) ++mex;
    vll b(n);
    f(i,n){
        if(cnt[a[i]]>1) b[i]=mex;
        else b[i]=min(a[i],mex);
    }
    return b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n);
        f(i,n) cin>>a[i];
        if(k>1) k=k%2+2;
        auto a1=one_step(a);
        auto a2=one_step(a1);
        auto a3=one_step(a2);
        if(k==0){
            cout<<accumulate(all(a),0LL)<<"\n";
        }
        else if(k==1){
            cout<<accumulate(all(a1),0LL)<<"\n";
        }
        else if(k==2){
            cout<<accumulate(all(a2),0LL)<<"\n";
        }
        else if(k==3){
            cout<<accumulate(all(a3),0LL)<<"\n";
        }
    }
    return 0;
}