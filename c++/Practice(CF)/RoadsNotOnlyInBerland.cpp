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
    Size[v]=1LL;
}

lli find(lli v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);        //path compression
}

void Union(lli a,lli b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);     //union by size
        parent[b]=a;
        Size[a]+=Size[b];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;           //n->number of nodes
    cin>>n;
    ff(1,n+1,1){
        make(i);
    }
    lli k=n-1;
    vector<pair<lli,lli>> cycles;
    while(k--){
        lli u,v;
        cin>>u>>v;
        if(find(u)==find(v)){
            cycles.push_back({u,v});
        }
        Union(u,v);
    }
    set<lli> toConnect;
    lli connected_ct=0;
    ff(1,n+1,1){
        if(find(i)==i){
            connected_ct++;
            toConnect.insert(i);
        }
    }
    cout<<connected_ct-1<<"\n";
    for(auto it=toConnect.begin();it!=toConnect.end(); ){
        if(find(*it)==find(1)) it=toConnect.erase(it);
        else ++it;
    }
    fa(cycles){
        lli u=it.first,v=it.second;
        cout<<u<<" "<<v<<" ";
        lli node=*toConnect.begin();
        cout<<1<<" "<<node<<"\n";
        toConnect.erase(toConnect.begin());
    }
    return 0;
}