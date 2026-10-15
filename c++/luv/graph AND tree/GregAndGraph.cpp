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
const lli N=501;
const lli M=1e9+7; 

lli d[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    for(lli i=1;i<=n;i++){
        for(lli j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }
    vll del(n);
    f(i,n) cin>>del[i];
    reverse(all(del));      //just apply Floyd Warshall after reversing Deletion order
    vll ans;
    for(lli k=0;k<n;k++){
        lli node=del[k];
        for(lli i=1;i<=n;i++){
            for(lli j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][node]+d[node][j]);
            }
        }
        // for(lli i=1;i<=n;i++){
        //     for(lli j=1;j<=n;j++){
        //         cout<<d[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        lli sum=0;
        for(lli i=0;i<=k;i++){
            for(lli j=0;j<=k;j++){
                sum+=d[del[i]][del[j]];                //sum of all distances considering node k
            }
        }
        ans.push_back(sum);
    }
    reverse(all(ans));
    fa(ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}