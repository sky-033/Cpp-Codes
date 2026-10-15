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
        vvll factors(n+1);
        for(lli i=2;i<=n;i++){
            for(lli j=i;j<=n;j+=i){
                factors[i].push_back(j);
            }
        }
        vll vis(n+1,0),ans(n+1,0);
        ans[1]=1;
        vis[1]=1;
        // for(lli i=2;i<=n;i++){
        //     for(lli j=0;j<factors[i].size();j++){
        //         cout<<factors[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(lli i=n/2;i>=2;i--){
            if(factors[i].size()>=2){
                lli l=0,h=1;
                while(h<factors[i].size() && l<factors[i].size()){
                    lli l1=factors[i][l],r1=factors[i][h];
                    if(vis[l1]==0 && vis[r1]==0 && l1!=r1){
                        ans[l1]=r1;
                        ans[r1]=l1;
                        vis[l1]=1;
                        vis[r1]=1;
                        l+=2;
                        h+=2;
                    }
                    else if(vis[l1]) l++;
                    else if(vis[r1]) h++;
                    else{
                        l++,h++;
                    }
                }
            }
        }
        ff(1,n+1,1){
            if(ans[i]==0) cout<<i<<" ";
            else cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}