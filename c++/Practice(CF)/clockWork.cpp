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
        for(int i=0;i<n;i++){
            if(a[i]<=2*(n-i-1) || a[i]<=2*i){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}


