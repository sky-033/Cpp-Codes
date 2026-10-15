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
const lli N=1001;
const lli M=1e9+7; 



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,x;
        cin>>n>>x;
        vll g[n+1];
        f(i,n-1){
            lli u,v;
            cin>>u>>v;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        lli left=1;
        left+=g[x].size();
        if(g[x].size()<=1) cout<<"Ayush"<<endl;
        else{
            if((n-left)%2){
                if(left%2){
                    cout<<"Ayush"<<endl;
                }
                else{
                    cout<<"Ashish"<<endl;
                }
            }
            else{
                if(left%2){
                    cout<<"Ashish"<<endl;
                }
                else{
                    cout<<"Ayush"<<endl;
                }
            }
        }
    }
    return 0;
}