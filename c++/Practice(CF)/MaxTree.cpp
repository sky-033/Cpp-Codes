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
        vvll g(n+1);
        vll indeg(n+1,0);
        f(i,n-1){
            lli u,v,x,y;
            cin>>u>>v>>x>>y;
            if(x>y){
                g[u].push_back(v);
                indeg[v]++;
            }
            else{
                g[v].push_back(u);
                indeg[u]++;
            }
        }
        queue<lli> q;
        ff(1,n+1,1){
            if(indeg[i]==0) q.push(i);
        }
        vll order;
        while(!q.empty()){
            lli node=q.front();
            q.pop();
            order.push_back(node);
            for(auto child:g[node]){
                indeg[child]--;
                if(indeg[child]==0) q.push(child);
            }
        }
        vll p(n+1);
        lli st=n;
        fa(order){
            p[it]=st;
            st--;
        }
        ff(1,n+1,1) cout<<p[i]<<" ";
        cout<<'\n';
    }
    return 0;
}