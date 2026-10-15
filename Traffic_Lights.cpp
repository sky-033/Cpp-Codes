#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    //NO duplicate
template <typename T>using ordered_multiset = tree<pair<T, lli>,null_type,less<pair<T, lli>>,rb_tree_tag,tree_order_statistics_node_update>;   //Allows duplicate
//s.order_of_key(k) -->  Returns the number of elements smaller than k.
//*s.find_by_order(k) --> Returns the element present at index k.
#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli x,n;
    cin>>x>>n;
    multiset<lli> mt;
    mt.insert(x);
    set<lli> st;
    st.insert(0);
    st.insert(x);
    f(i,n){
        lli p;
        cin>>p;
        auto it1=st.lower_bound(p);
        auto left=it1,right=it1;
        left--;
        lli val=*right-*left;
        mt.erase(mt.find(val));
        mt.insert(p-*left);
        mt.insert(*right-p);
        st.insert(p);
        cout<<*mt.rbegin()<<" ";
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}