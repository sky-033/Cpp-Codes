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
lli n,m;
bool check(lli i1,lli j1,vvll &a,lli ct,lli maxi){
    lli ctt=1;
    for(lli j=0;j<m;j++){
        if(j==j1) continue;
        if(a[i1][j]==maxi) ctt++;
    }
    for(lli i=0;i<n;i++){
        if(i==i1) continue;
        if(a[i][j1]==maxi) ctt++;
    }
    return ct==ctt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vvll a(n,vll(m));
        lli maxi=0,ct=0;
        f(i,n){
            g(j,m){
                cin>>a[i][j];
                maxi=max(maxi,a[i][j]);
            }
        }
        lli i1=-1,j1=-1;
        f(i,n){
            g(j,m){
                if(a[i][j]==maxi){
                    ct++;
                    i1=i;
                    j1=j;
                }
            }
        }
        bool flag=false;
        f(i,n){
            flag=check(i,j1,a,ct,maxi);
            if(flag) break;
        }
        f(j,m){
            flag=check(i1,j,a,ct,maxi);
            if(flag) break;
        }
        if(flag) cout<<maxi-1<<endl;
        else cout<<maxi<<endl;
    }
    return 0;
}