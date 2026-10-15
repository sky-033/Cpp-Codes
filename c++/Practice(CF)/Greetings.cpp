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
const lli N=2e5+10;
const lli M=1e9+7; 
template <typename T> using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vp pairs(n);
        map<lli,lli> freq,order;
        ordered_multiset<int> store;
        f(i,n){
            lli x,y;
            cin>>x>>y;
            pairs[i]={x,y};
            freq[x]++;
        }
        // fa(freq) cout<<it.first<<" "<<it.second<<endl;
        // sor(end);
        lli s=0;
        sor(pairs);
        lli ct=1;
        for(lli i=n-1;i>=0;i--){
            order[pairs[i].second]=ct;
            ct++;
        }
        lli greetings=0;
        for(lli i=n-1;i>=0;i--){
            s=store.size();
            lli val=pairs[i].second;
            if(store.size()>0){
                greetings+=store.order_of_key(val+1);
            }
            store.insert(val);
        }
        // fa(maxi) cout<<it.first<<" "<<it.second<<endl;
        lli l=0;
        
        while(l<n){
            lli first=pairs[l].first;
            lli second=pairs[l].second;
            if(freq[first]>1){
                greetings+=second;
                freq[first]--;
            }
            l++;
        }
        cout<<greetings<<endl;
    }
    return 0;
}