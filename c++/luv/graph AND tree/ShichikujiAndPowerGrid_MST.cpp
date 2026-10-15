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
const lli N=2e3+10;
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
    lli n;
    cin>>n;
    ff(0,n+1,1) make(i);
    vp cities(n+1);
    ff(1,n+1,1){
        cin>>cities[i].first>>cities[i].second;
    }
    vll c(n+1),k(n+1);
    vector<pair<lli,pair<lli,lli>>> edges;
    ff(1,n+1,1) cin>>c[i];
    ff(1,n+1,1) cin>>k[i];
    
    ff(1,n+1,1){
        for(lli j=i+1;j<=n;j++){
            lli cost=(k[i]+k[j])*(abs(cities[i].first-cities[j].first)+abs(cities[i].second-cities[j].second));
            edges.push_back({cost,{i,j}});
        }
    }
    ff(1,n+1,1){
        edges.push_back({c[i],{0,i}});
    }
    
    sor(edges);
    lli total_cost=0;
    vll powerStation;
    vp connection;
    for(auto &edge:edges){
        lli wt=edge.first;
        lli u=edge.second.first;
        lli v=edge.second.second;
        if(find(u)==find(v)) continue;
        total_cost+=wt;
        Union(u,v);
        if(u==0 || v==0) powerStation.push_back(max(u,v));
        else connection.push_back({u,v});
    }
    sor(powerStation),sor(connection);
    cout<<total_cost<<endl;
    cout<<powerStation.size()<<endl;
    fa(powerStation) cout<<it<<" ";
    cout<<endl;
    cout<<connection.size()<<endl;
    fa(connection) cout<<it.first<<" "<<it.second<<endl;
    return 0;
}