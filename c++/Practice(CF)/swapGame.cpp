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
        bool flag=false;
        for(int i=0;i<n;i++){
            if(a[0]-a[i]>0){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}