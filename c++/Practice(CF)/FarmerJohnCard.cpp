#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vvll a(n);
        vll ans(n);
        f(i,n){
            a[i].resize(m);
            for(lli j=0;j<m;j++){
                cin>>a[i][j];
            }
            sort(a[i].begin(),a[i].end());
        }
        bool flag=true;
        f(i,n){
            for(lli j=1;j<m;j++){
                if(a[i][j]-a[i][j-1]!=n){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            f(i,n){
                ans[a[i][0]]=i+1;
            }
            f(i,n) cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}