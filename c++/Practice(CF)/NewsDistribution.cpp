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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=5e5+10;

vll Size(N);
vll par(N);

void make(lli vertex){
    Size[vertex]=1;
    par[vertex]=vertex;
}

lli find(lli vertex){
    if(vertex==par[vertex]) return vertex;
    return par[vertex]=find(par[vertex]);
}

void Union(lli a,lli b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(Size[a]<Size[b]) swap(a,b);
        Size[a]+=Size[b];
        par[b]=a;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    ff(1,n+1,1){
        make(i);
    }
    f(i,m){
        lli k;
        cin>>k;
        vll vec(k);
        g(j,k) cin>>vec[j];
        for(lli j=0;j<k-1;j++){
            lli u=vec[j];
            lli v=vec[j+1];
            if(find(u)==find(v)) continue;
            Union(u,v);
        }
    }
    ff(1,n+1,1) cout<<Size[find(i)]<<" ";
    cout<<endl;
    return 0;
}