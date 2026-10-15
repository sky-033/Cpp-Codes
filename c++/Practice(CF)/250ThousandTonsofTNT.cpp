#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<lli> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        lli ans=-1;
        for(int d=1;d<=n;d++){
            if(n%d==0){                // since d should be divisible by n(trucks should have same no. of boxes)
                lli maxi=-1e18,mini=1e18;
                for(int i=0;i<n;i+=d){
                    lli sum=0;
                    for(int j=i;j<d+i;j++){
                        sum+=a[j];
                    }
                    maxi=max(sum,maxi);
                    mini=min(sum,mini);
                }
                ans=max(maxi-mini,ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
