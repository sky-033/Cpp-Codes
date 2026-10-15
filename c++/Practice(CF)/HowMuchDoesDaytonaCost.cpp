#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        bool flag=false;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(k==a[i]){
                flag=true;
                // break;
            }
        }
        cout<<(flag? "YES":"NO")<<endl;
        
    }
    return 0;
}