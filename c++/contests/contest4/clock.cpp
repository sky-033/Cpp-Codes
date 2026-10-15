#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N=5e5+10;
        int hsh[N];
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            hsh[i]=a[i]-n;
        }
        if(n==2){
            if(a[0]>2 && a[1]>2) cout<<"YES"<<endl;
            else cout<<"NO";
        }
        else{
            
        }


    }
    return 0;
}