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
        lli n,m;
        cin>>n>>m;
        vvll v(n);
        lli ct=0,sum=0,mini=1e18;
        f(i,n){
            v[i].resize(m);
            f(j,m){
                cin>>v[i][j];
                if(v[i][j]<0){
                    ct++;
                    v[i][j]*=(-1);
                }
                sum+=v[i][j];
                mini=min(mini,v[i][j]);
            }
        }
        f(i,n){
            f(j,m) cout<<v[i][j]<<" ";
            cout<<endl;
        }
        // if(ct%2) cout<<sum-2*mini<<endl;
        // else cout<<sum<<endl;
    }
    return 0;
}