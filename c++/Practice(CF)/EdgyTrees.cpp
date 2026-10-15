// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vpw vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define rf(i,n) for(lli i=n-1;i>=0;i--)
// #define ff(a,b,c) for(lli i=a;i<b;i+=c)
// #define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
// #define fa(v) for (auto &it : v) 
// #define all(x) (x).begin(), (x).end()
// #define sor(x) sort(all(x))
// #define setbits(x) __builtin_popcountll(x)
// #define bitlen(x) 64-__builtin_clzll(x)
// const lli N=2e5+10;
// const lli M=1e9+7; 

// bool vis[N];
// lli total,k;
// vll g[N];
// map<pair<lli,lli>,lli> v;

// lli binExpItr(lli a,lli b){
//     lli ans=1;
//     a%=M;
//     while(b>0){
//         if(b&1) ans=(ans*a)%M;
//         a=(a*a)%M;
//         b>>=1;
//     }
//     return ans;
// }

// void dfs(lli vertex,lli &ct){
//     vis[vertex]=1;
//     ct++;
//     for(auto child:g[vertex]){
//         if(!vis[child] && v[{vertex, child}]==0){
//             dfs(child,ct);
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     lli n;
//     lli timess=0;
//     cin>>n>>k;
//     f(i,n-1){
//         lli x,y,a;
//         cin>>x>>y>>a;
//         if(a) timess++;
//         g[x].push_back(y);
//         g[y].push_back(x);
//         v[{x,y}]=a;
//         v[{y,x}]=a;
//     }
//     total=binExpItr(n,k);
//     for(lli i=1;i<=n;i++){
//         if(!vis[i]){
//             lli ct=0;
//             dfs(i, ct);
//             total=(total-binExpItr(ct, k)+M)%M;
//         }
//     }
//     cout<<(total)<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vpw vector<pair<lli,lli>>
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

lli binExpItr(lli a,lli b){
    lli ans=1;
    a%=M;
    while(b>0){
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

vll g[N];
vector<bool> vis(N);
vvll cc;
vll current_cc;
void dfs(lli vertex){
    current_cc.push_back(vertex);
    vis[vertex]=true;
    for(auto child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,k;
    cin>>n>>k;
    f(i,n-1){
        lli x,y,a;
        cin>>x>>y>>a;
        if(a==0){
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    ff(1,n+1,1){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }
    lli total=binExpItr(n,k);
    fa(cc){
        lli s=it.size();
        s=binExpItr(s,k);
        total=((total%M)-(s%M)+M)%M;
    }
    cout<<total<<endl;
    return 0;
}