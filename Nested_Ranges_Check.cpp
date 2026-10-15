#include<bits/stdc++.h>
using namespace std;
#define lli long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    //NO duplicate
template <typename T>using ordered_multiset = tree<pair<T, lli>,null_type,less<pair<T, lli>>,rb_tree_tag,tree_order_statistics_node_update>;   //Allows duplicate
//s.order_of_key(k) -->  Returns the number of elements smaller than k.
//*s.find_by_order(k) --> Returns the element present at index k.

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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
    vector<pair<pair<lli,lli>,lli>> a(n),b(n);
    ordered_multiset<lli> st,st1;
    f(i,n){
        lli x,y;
        cin>>x>>y;
        st.insert({x,i+1});
        st1.insert({y,i+1});
        a[i]={{x,y},i+1};
        b[i]={{y,x},i+1};
    }
    sort(b.begin(), b.end(), [](auto &a, auto &b) {
        if (a.first.first == b.first.first) return a.first.second > b.first.second;  
        return a.first.first < b.first.first;      
    });
    sort(a.begin(), a.end(), [](auto &A, auto &B){
        if(A.first.first == B.first.first) return A.first.second > B.first.second;
        return A.first.first < B.first.first;
    });
    vll a1(n),b1(n);
    f(i,n){
        lli x=b[i].first.second,y=b[i].first.first,indx=b[i].second;
        auto it=st.lower_bound({x,0});
        if(it!=st.end() && it->first==x) st.erase(it);
        
        if(st.order_of_key({x+1,0})>0) b1[indx-1]=1;  
        else b1[indx-1]=0;
    }
    f(i,n){
        lli y=a[i].first.second,x=a[i].first.first,indx=a[i].second;
        auto it=st1.lower_bound({y,0});
        if(it!=st.end() && it->first==y) st1.erase(it);

        if(st1.order_of_key({y+1,0})>0) a1[indx-1]=1; 
        else a1[indx-1]=0;
    }
    f(i,n) cout<<a1[i]<<" ";
    cout<<endl;
    f(i,n) cout<<b1[i]<<" ";
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