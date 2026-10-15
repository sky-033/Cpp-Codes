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
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k,a,b;
        cin>>n>>k>>a>>b;
        vp xy;
        f(i,n){
            lli x,y;
            cin>>x>>y;
            xy.push_back({x,y});
        }
        lli minia=1e18,minib=1e18;
        lli ax=xy[a-1].first;
        lli ay=xy[a-1].second;
        lli bx=xy[b-1].first;
        lli by=xy[b-1].second;
        lli total=abs(ax-bx)+abs(ay-by);
        if(k>=2){
            f(i,k){
                lli x1=xy[i].first;
                lli y1=xy[i].second;
                lli dista=abs(ax-x1)+abs(ay-y1);
                lli distb=abs(bx-x1)+abs(by-y1);
                minia=min(dista,minia);
                minib=min(distb,minib);
            }
            cout<<min(total,minia+minib)<<endl;
        }
        else cout<<total<<endl;
    }
    return 0;
}