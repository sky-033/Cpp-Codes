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
        lli n,k;
        cin>>n>>k;
        vll hi(n),ans;
        f(i,n) cin>>hi[i];
        ans.push_back(hi[k-1]);
        f(i,n){
            if(hi[i]>hi[k-1]) ans.push_back(hi[i]);
        }
        if(ans.size()==1) cout<<"YES"<<endl;
        else{
            lli level=1;
            sor(ans);
            set<lli> op;
            ff(0,ans.size(),1){
                op.insert(ans[i]);
            }
            auto it=op.begin();
            auto prv=it;
            it++;
            bool flag=true;
            for(;it!=op.end();it++,prv++){
                lli time=*it-*prv;
                lli timeR=*prv-level+1;
                // cout<<time<<" "<<timeR<<endl;
                level+=time;
                if(time>timeR){
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}