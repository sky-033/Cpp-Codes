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
        map<lli,vector<lli>> mp;
        lli total=0;
        vll u(n),s(n);
        f(i,n) cin>>u[i];
        f(i,n) cin>>s[i];
        f(i,n){
            total+=s[i];
            mp[u[i]].push_back(s[i]);
        }
        vll ans(n+1,0);
        fa(mp){
            sor(it.second);
            for(lli i=1;i<it.second.size();i++){
                it.second[i]+=it.second[i-1];
            }

            for(lli i=1;i<=it.second.size();i++){
                lli left=it.second.size()%i;
                if(left!=0) ans[i]+=(it.second[it.second.size()-1]-it.second[left-1]);
                else ans[i]+=(it.second[it.second.size()-1]);
            }
        }
        ff(1,n+1,1) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}