#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

vll g[N];
vll pari(N);

void dfs(lli vertex,lli par=-1){
    pari[vertex]=par;
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
    }
}

vll path(lli vertex){
    vll ans;
    while(vertex!=-1){
        ans.push_back(vertex);
        vertex=pari[vertex];
    }
    reverse(all(ans));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    f(i,n-1){
        lli x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    lli x,y;
    cin>>x>>y;
    vll path_x=path(x);
    vll path_y=path(y);
    
    lli size=min(path_x.size(),path_y.size());
    lli LCA;
    f(i,size){
        if(path_x[i]==path_y[i]){
            LCA=path_x[i];
            // cout<<path_x[i]<<" ";
        }
        else break;
    }
reverse(path_x.begin(),path_x.end());
                reverse(path_y.begin(),path_y.end());
                fa(path_x) cout<<it<<" ";
    cout<<endl;
    fa(path_y) cout<<it<<" ";
    cout<<endl;
                    set<lli> st;
                
                for(auto it : path_x){
                    if(it==LCA) break;
                    else st.insert(it);
                }
                for(auto it : path_y){
                    if(it==LCA) break;
                    else st.insert(it);
                }
                fa(st) cout<<it<<" ";
    // cout<<LCA<<endl;
    return 0;
}