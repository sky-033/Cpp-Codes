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
vll color(N,-1);

bool check(lli st){
    queue<lli> q;
    q.push(st);
    color[st]=0;
    while(!q.empty()){
        lli node=q.front();
        q.pop();
        fa(g[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]) return false;
        }
    }
    return true;
}
bool isBipartite(lli n){
    ff(1,n+1,1){
        if(color[i]==-1){
            if(check(i)==false){
                return false;
            }
        }
    }
    return true;
}

void reset(lli n){
    ff(1,n+1,1){
        color[i]=-1;
        g[i].clear();
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
        map<lli,lli> mpp;
        bool flag=true;
        f(i,n){
            lli u,v;
            cin>>u>>v;
            mpp[u]++;
            mpp[v]++;
            if(mpp[u]>2 || mpp[v]>2 || u==v) flag=false;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(flag){
            flag=isBipartite(n);
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}