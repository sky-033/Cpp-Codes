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
        lli sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==2){
            cout<<a[1]-a[0]<<endl;
        }
        else{
            for(int i=0;i<n-2;i++){
            sum+=a[i];
            }
            cout<<a[n-1]-(a[n-2]-sum)<<endl;        
        }
    }
    return 0;
}