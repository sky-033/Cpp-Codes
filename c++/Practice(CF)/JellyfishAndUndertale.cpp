#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        lli a,b,n;
        cin>>a>>b>>n;
        vector<lli> x(n+1);
        lli ct=1,sum=b-1;;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(ct+x[i]<=a){
                sum+=x[i];
            }
            else{
                sum+=a-1;
            }
        }
        cout<<sum+1<<endl;
    }
    return 0;
}