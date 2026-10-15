// #include<bits/stdc++.h>
// using namespace std;

// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define ff(a,b,c) for(lli i=a;i<b;i+=c)
// #define fa(v) for (auto &it : v) 
// #define all(x) (x).begin(), (x).end()
// #define setbits(x) __builtin_popcountll(x)
// #define bitlen(x) 64-__builtin_clzll(x)
// #define yes cout << "YES" << '\n'
// #define no cout << "NO" << '\n'
// #define endl '\n'
// const lli N=2e5+10;
// const lli M=1e9+7;

// #ifndef ONLINE_JUDGE
// #include "debuG.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif


// struct Node {
//     long long sum;
//     Node() {
//         sum = 0LL;
//     }
// };

// Node tree[4 * N];

// Node merge(Node a, Node b) {
//     Node ans;
//     ans.sum = a.sum + b.sum;
//     return ans;
// }

// void build(long long id, long long l, long long r) {
//     if (l == r) {
//         tree[id].sum = 1LL;
//         return;
//     }

//     long long mid = l + (r - l) / 2;
//     build(2LL * id, l, mid);
//     build(2LL * id + 1LL, mid + 1LL, r);

//     tree[id] = merge(tree[2LL * id], tree[2LL * id + 1LL]);
// }

// void update(long long id, long long l, long long r,
//             long long pos) {

//     if (pos < l || pos > r) return;

//     if (l == r) {
//         tree[id].sum = 0LL;
//         return;
//     }

//     long long mid = l + (r - l) / 2;

//     if (pos <= mid)
//         update(2LL * id, l, mid, pos);
//     else
//         update(2LL * id + 1LL, mid + 1LL, r, pos);

//     tree[id] = merge(tree[2LL * id], tree[2LL * id + 1LL]);
// }

// long long query(long long id, long long l, long long r,long long p) {

//     if(l==r){
//         return l;
//     }
    
//     long long mid = l + (r - l) / 2;

//    if (tree[2LL * id].sum >= p)
//         return query(2LL * id, l, mid, p);
//     else
//         return query(2LL * id + 1LL, mid + 1LL, r,
//                    p - tree[2LL * id].sum);
// }


// void solve(){
//     lli n;
//     cin>>n;
//     vll a(n);
//     f(i,n) cin>>a[i];
//     build(1,0,n-1);
//     f(i,n){
//         lli p;
//         cin>>p;
//         cout<<a[query(1,0,n-1,p)]<<" ";
//         update(1,0,n-1,query(1,0,n-1,p));
//     }
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     lli t=1;
//     while(t--){
//         solve();
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    //NO duplicate
//template <typename T>using ordered_multiset = tree<pair<T, lli>,null_type,less<pair<T, lli>>,rb_tree_tag,tree_order_statistics_node_update>;   //Allows duplicate
//s.order_of_key(k) -->  Returns the number of elements smaller than k.
//*s.find_by_order(k) --> Returns the element present at index k.

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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
    vll a(n);
    ordered_set<lli> os;
    f(i,n){
        lli x;
        cin>>x;
        a[i]=x;
        os.insert(i);
    }
    // debug(os);
    f(i,n){
        lli p;
        cin>>p;
        auto it=os.find_by_order(p-1);
        cout<<a[*it]<<" ";
        os.erase(it);
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