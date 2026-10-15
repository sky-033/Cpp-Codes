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
vll g[N];
vll vis(N);
vvll cc;
vll current_cc;
void reset(lli n){
    ff(1,n+1,1){
        g[i].clear();
        vis[i]=0;
    }
    cc.clear();
    current_cc.clear();
}
void dfs(lli vertex){
    current_cc.push_back(vertex);
    vis[vertex]=1;
    for(auto child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        reset(n);
        set<lli> g1[n+1];
        f(i,n){
            lli u=i+1,v;
            cin>>v;
            g1[u].insert(v);
            g1[v].insert(u);
        }
        ff(1,n+1,1){
            fa(g1[i]){
                g[i].push_back(it);
            }
        }
        lli ct=0;
        ff(1,n+1,1){
            if(vis[i]) continue;
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
            ct++;
        }
        lli noOp=0;
        bool flag=true;
        for(auto vec:cc){
            flag=true;
            fa(vec){
                if(g[it].size()==1){
                    flag=false;
                    break;
                }
            } 
            if(flag) noOp++;
        }
        lli maxi=ct;
        lli mini=noOp;
        ct-=noOp;
        if(ct>0) mini++;
        cout<<mini<<" "<<maxi<<"\n";
    }
    return 0;
}