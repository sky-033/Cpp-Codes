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

bool find(vp &dim){
    lli area=0;
    fa(dim){
        area+=it.first*it.second;
    }
    lli sq=sqrt(area);
    if(sq*sq!=area) return false;
    vll l(3),b(3);
    f(i,3){
        l[i]=dim[i].first;
        b[i]=dim[i].second;
    }
    if(all_of(l.begin(),l.end(), [&](lli x){ return x==sq; }) && b[0]+b[1]+b[2]==sq) return true;
    if(all_of(b.begin(),b.end(), [&](lli x){ return x==sq; }) && l[0]+l[1]+l[2]==sq) return true;
    f(i,3){
        if(l[i]==sq &&l[i]<sq) {
            lli remB=sq-l[i];
            vp now;
            for(lli j=0;j<3;j++) if(j!=i) now.push_back(dim[j]);
            if (now[0].first==remB && now[1].first == remB && now[0].second+ now[1].second==sq) return true;
        }
    }
    f(i,3){
        if(b[i]==sq &&b[i]<sq) {
            lli remB=sq-b[i];
            vp now;
            for(lli j=0;j<3;j++) if(j!=i) now.push_back(dim[j]);
            if (now[0].first==remB && now[1].first == remB && now[0].second+ now[1].second==sq) return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        vp dim(3);
        f(i,3){
            cin>>dim[i].first;
            cin>>dim[i].second;
        }
        bool flag=find(dim);
        cout<<(flag? "YES":"NO")<<endl;
    }
    return 0;
}