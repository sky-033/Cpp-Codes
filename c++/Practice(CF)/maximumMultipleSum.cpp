#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0,maxi=0;
        for(int x=2;x<=n;x++){
            int sum=0;
            for(int i=0;i<=n;i++){
                if(x*i<=n){
                    sum+=x*i;
                }
            }
            if(maxi<sum){
                maxi=sum;
                ans=x;
            }
            
        }
        cout<<ans<<endl;

    }
    return 0;
}