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
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    //NO duplicate
//template <typename T>using ordered_multiset = tree<pair<T, lli>,null_type,less<pair<T, lli>>,rb_tree_tag,tree_order_statistics_node_update>;   //Allows duplicate
//s.order_of_key(k) -->  Returns the number of elements smaller than k.
//*s.find_by_order(k) --> Returns the element present at index k.
#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n,k;
    cin>>n>>k;
    ordered_set<lli> st;
    ff(1,n+1,1) st.insert(i);
    lli indx=0;
    while(st.size()>0){
        indx=(indx+k)%st.size();
        auto it=st.find_by_order(indx);

        cout<<*it<<" ";
        st.erase(it);
    }
    cout<<endl;
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