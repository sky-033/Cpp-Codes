// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define g(j,n) for(lli j=0;j<n;j++)
// #define h(k,n) for(lli k=0;k<n;k++)
// #define rf(i,n) for(lli i=n-1;i>=0;i--)
// #define ff(a,b,c) for(lli i=a;i<b;i+=c)
// #define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
// #define fa(v) for (auto &it : v) 
// #define all(x) (x).begin(), (x).end()
// #define sor(x) sort(all(x))
// #define setbits(x) __builtin_popcountll(x)
// const lli N=2e5+10;
// const lli M=1e9+7; 

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         lli n,m;
//         cin>>n>>m;
//         vll a(n),b(n);
//         a[0]=1;
//         ff(1,n,1) cin>>a[i];
//         f(i,n) cin>>b[i];
//         sor(a),sor(b);
//         reverse(all(a)),reverse(all(b));
//         lli ct=0;
//         lli l1=0,l2=0;
//         while(l1<n){
//             if(b[l2]>a[l1]){
//                 ct++;
//                 l1++,l2++;
//             }
//             else l1++;
//         }
//         cout<<n-ct<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define lli long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    //NO duplicate
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

// #ifndef ONLINE_JUDGE
// #include "debuG.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif

bool check(vll &a,vll& b,lli n,lli mid){
    if(mid==0) return true;
    lli indx=mid-1;
    lli j=n-1;
    for(lli i=indx;i>=0;i--){
        if(a[i]>=b[j--]) return false;
    }
    return true;
}
void solve(){
    lli n,m;
    cin>>n>>m;
    vll a(n),b(n);
    // ordered_multiset<lli> ms;
    a[0]=1;
    f(i,n-1) cin>>a[i+1];
    f(i,n){
        cin>>b[i];
       // ms.insert({b[i],i+1});
    }
    sort(all(a)),sort(all(b));
    lli l=0,h=n;
    while(h-l>1){
        lli mid=(l+h)/2;
        if(check(a,b,n,mid)){
            l=mid;
        }
        else{
            h=mid-1;
        }
    }
    if(check(a,b,n,h)) cout<<n-h<<endl;
    else cout<<n-l<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}