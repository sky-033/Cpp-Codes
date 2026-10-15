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
        vll a(n);
        lli maxi=-1e18;
        lli mini=1e18;
        f(i,n){
            cin>>a[i];
            maxi=max(maxi,a[i]);
            mini=min(mini,a[i]);
        }
        // if(a[0]-mini==0 || a[n-1]-maxi==0){
        //     cout<<(maxi-mini)<<endl;
        // }
        // else{
            lli maxx=0;
            for(lli i=0;i<n-1;i++){
                maxx=max(maxx,a[i]-a[i+1]);
            }
            maxx=max(maxi-a[0],maxx);
            maxx=max(maxx,a[n-1]-mini);
            cout<<maxx<<endl;
        // }
    }
    return 0;
}