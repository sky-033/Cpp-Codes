#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vvll v(n);
        lli mini=1e18,ans=0,indx=0,mini2=1e18;
        f(i,n){
            lli m;
            cin>>m;
            v[i].resize(m);
            for(lli j=0;j<m;j++) cin>>v[i][j];
            sort(v[i].begin(),v[i].end());
        }
        f(i,n){
            if(v[i][0]<mini){
                mini=v[i][0];
            }
            if(v[i][1]<mini2){
                mini2=v[i][1];
                indx=i;
            }
        }
        ans+=mini;
        f(i,n){
            if(i==indx) ans+=0;
            else ans+=v[i][1];
        }
        // cout<<mini<<" "<<mini2<<" "<<indx<<endl;
        cout<<ans<<endl;
    }
    return 0;
}