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
const lli N=1e5+10;
const lli M=1e9+7; 

vll Size(N);
vll parent(N);
multiset<lli> sizes;

void make(lli v){
    parent[v]=v;
    Size[v]=1;
    sizes.insert(1);
}

lli find(lli v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void merge(lli a,lli b){
    sizes.erase(sizes.find(Size[a]));
    sizes.erase(sizes.find(Size[b]));
    sizes.insert(Size[a]+Size[b]);
}

void Union(lli a,lli b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);
        parent[b]=a;
        merge(a,b);
        Size[a]+=Size[b];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,q;
    cin>>n>>q;
    ff(1,n+1,1) make(i);
    while(q--){
        lli u,v;
        cin>>u>>v;
        Union(u,v);
		if(sizes.size()==1) cout<<0<<endl;
		else{
			lli mini=*(sizes.begin());
            lli maxi=*(--sizes.end());
            cout<<maxi-mini<<endl;
		}
        
    }

    return 0;
}