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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n);
        vvll diff(n+1);
        f(i,n){
            cin>>a[i];
            diff[a[i]].push_back(i+1);
        }
        map<lli,lli> ans;
        for(lli i=1;i<=n;i++){
            if(diff[i].size()>0){
                lli maxi=-1e9;
                for(lli j=0;j<diff[i].size()-1;j++) maxi=max(maxi,diff[i][j+1]-diff[i][j]-1);
                maxi=max(maxi,diff[i][0]-1);
                maxi=max(maxi,n-diff[i][diff[i].size()-1]);
                ans[i]=maxi;
            }
        }
        // fa(ans) cout<<it.first<<" "<<it.second<<endl;
        vector<lli> k(n+1,-1);
        lli thres=n;
        fa(ans){
            lli s=it.second;
            if(s<thres){
                for(lli i=s+1;i<=thres;i++){
                    if(k[i]==-1) k[i]=it.first;
                }
                thres=s;
            }
            if(thres==0) break;
        }
        ff(1,n+1,1) cout<<k[i]<<" ";
        cout<<"\n";
    }
    return 0;
}