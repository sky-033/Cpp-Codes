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
vll spf(N);

vector<multiset<lli>> ans(N);
lli binExpItr(lli a,lli b){
    lli ans=1;
    while(b){
        if(b&1) ans=ans*a;
        a*=a;
        b>>=1;
    }
    return ans;
}

void sieve(){
    f(i,N) spf[i]=i;
    spf[0]=0,spf[1]=1;
    ff(2,N,1){
        if(spf[i]==i){
            for(lli j=i*i;j<+N;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

vp factorise(lli n){
    vp res;
    while(n>1){
        lli p=spf[n],ct=0;
        while(n%p==0){
            ct++;
            n/=p;
        }
        res.push_back({p,ct});
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    lli n;
    cin>>n;
    vll a(n);
    f(i,n) cin>>a[i];
    f(i,n){
        auto f=factorise(a[i]);
        fa(f){
            ans[it.first].insert(it.second);
        }
    }
    lli val=1;
    ff(1,N,1){
        if(ans[i].size()>0){
            if(ans[i].size()==n){
                auto it=ans[i].begin();
                it++;
                val*=binExpItr(i,*it);
            }
            else if(ans[i].size()==n-1){
                auto it=ans[i].begin();
                val*=binExpItr(i,*it);
            }
        }
    }
    cout<<val<<"\n";
    return 0;
}