
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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    set<lli> st;
    ff(1,n+1,1){
        st.insert(i);
    }
    vll ans(n+1,0);
    f(i,m){
        lli l,r,x;
        cin>>l>>r>>x;
        auto l1=st.lower_bound(l);
        for(auto it=l1;it!=st.end() && *it<=r;){
            if(*it==x){
                ++it;
                continue;
            }
            ans[*it] = x;
            st.erase(it++); 
        }
    }
    // debug(ans);
    ff(1,n+1,1) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}