#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool flag=true;
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]<0){
                flag=false;
                break;
            }
            mini=min(a[i+1]-a[i],mini);
        }
        cout<<(flag? mini/2 +1 : 0)<<endl;

    }
    return 0;
}