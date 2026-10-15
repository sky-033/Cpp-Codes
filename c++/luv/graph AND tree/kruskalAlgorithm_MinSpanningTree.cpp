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

vll Size(N);
vll parent(N);

void make(lli v){
    parent[v]=v;
    Size[v]=1;
}

lli find(lli v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void Union(lli a,lli b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);
        Size[a]+=Size[b];
        parent[b]=a;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    vector<pair<lli,pair<lli,lli>>> edges;
    ff(1,n+1,1) make(i);
    f(i,m){
        lli u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(all(edges));
    lli cost=0;
    for(auto &edge:edges){
        lli wt=edge.first;
        lli u=edge.second.first;
        lli v=edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<cost<<endl;
    return 0;
}