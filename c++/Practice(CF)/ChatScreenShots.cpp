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
        lli n,k;
        cin>>n>>k;
        vvll a(k,vll(n));
        vll g[n+1];
        f(i,k){
            f(j,n){
                cin>>a[i][j];
            }
        }
        vll indeg(n+1,0);
        f(i,k){
            for(lli j=1;j<n-1;j++){
                lli u=a[i][j+1],v=a[i][j];
                g[v].push_back(u);
                indeg[u]++;
            }
        }
        vll order;
        queue<lli> q;
        ff(1,n+1,1){
            if(indeg[i]==0) q.push(i);
        }
        lli processed_nodes=0;
        while(!q.empty()){
            lli node=q.front();q.pop();
            order.push_back(node);
            processed_nodes++;
            fa(g[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
       
        if (processed_nodes == n) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}