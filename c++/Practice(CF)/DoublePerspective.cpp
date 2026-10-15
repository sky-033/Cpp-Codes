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
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vector<pair<pair<lli,lli>,lli>> id;
        f(i,n){
            lli u,v;
            cin>>u>>v;
            id.push_back({{u,v},i+1});
        }
        vll indx;
        sort(id.begin(), id.end(), [](const pair<pair<lli, lli>, lli>& a, const pair<pair<lli, lli>, lli>& b) {
            if (a.first.first != b.first.first)
            return a.first.first < b.first.first;
            return a.first.second > b.first.second; 
        });
        vll vis(2*n+1,0);
        fa(id){
            if(!vis[it.first.first]){
                indx.push_back(it.second);
                vis[it.first.first]=1;
            }
        }    
        cout<<indx.size()<<endl;
        fa(indx) cout<<it<<" ";
        cout<<endl;
        
    }
    return 0;
}