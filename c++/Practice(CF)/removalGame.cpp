#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        bool flag=true;
        if(a[0]==b[0]){
            for(int i=1;i<n;i++){
                if(a[i]!=b[i]) flag=false;
            }
        }
        else if(a[0]==b[n-1]){
            for(int i=1;i<n;i++){
                if(a[i]!=b[n-1-i]) flag=false;
            }
        }
        else{
            flag=false;
        }
        if(flag==true) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}