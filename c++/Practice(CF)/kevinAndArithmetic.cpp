#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int ct_even=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if((a[i]&1)==0) ct_even++; 
        }
        if(n==1){
            if(a[0]&1) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else if(ct_even==0) cout<<n-1<<endl;
        else cout<<n-ct_even+1<<endl;
    }
    return 0;
}