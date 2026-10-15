#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T>
using ordered_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll v(n),p(n);
        f(i,n) cin>>v[i];
        f(i,n) cin>>p[i];
        ordered_multiset<pair<lli,lli>> s;
        f(i,n){
            s.insert({v[p[i]-1],p[i]});
        }
        lli maxi=-1,ansK=-1;
        f(i,n/2+1){
            lli k=i+1;
            auto it=s.find_by_order(s.size()-k);
            if(k*(it->first)>maxi){
                maxi=k*(it->first);
                ansK=k;
            }
            auto toDel=s.find({v[p[i]-1],p[i]});
            lli st=p[i];
            s.erase(toDel);
            s.insert({0,st});
        }
        cout<<maxi<<" ";
        cout<<ansK<<"\n";
        
    }
    return 0;
}