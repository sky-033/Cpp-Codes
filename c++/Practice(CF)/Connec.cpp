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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 
lli n;
void dfs(lli i,lli j, vvll &grid,vp &v){
    if(i<=0 || j<=0) return;
    if(i>n || j>n) return;
    if(grid[i][j]!=0) return;
    grid[i][j]=2;
    v.push_back({i,j});
    dfs(i-1,j,grid,v);
    dfs(i,j-1,grid,v);
    dfs(i+1,j,grid,v);
    dfs(i,j+1,grid,v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    lli r1,r2,c1,c2;
    cin>>r1>>c1>>r2>>c2;
    vvll grid(n+1,vll(n+1));
    vp v1,v2;
    for(lli i=1;i<=n;i++){
        string s;
        cin>>s;
        for(lli j=1;j<=n;j++){
            grid[i][j]=s[j-1]-'0';
        }
    }
    dfs(r1,c1,grid,v1);
    dfs(r2,c2,grid,v2);
    lli dis=1e9;
    // fa(v1) cout<<it.first<<" "<<it.second<<endl;
    fa(v1){
        lli a1=it.first,b1=it.second;
        for(auto val:v2){
            lli a2=val.first,b2=val.second;
            dis=min(dis,(a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
        }
    }
    if(dis==1e9) cout<<0<<"\n";
    else cout<<dis<<"\n";
    return 0;
}