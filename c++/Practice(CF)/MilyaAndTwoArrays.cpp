#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_map<int,int> m1,m2;
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            m1[a[i]]++;
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            m2[b[i]]++;
        }
        bool f1=true,f2=true;
        for(auto &it:m1){
            if(it.second==n){
                f1=false;
            }
        }
        for(auto &it:m2){
            if(it.second==n){
                f2=false;
            }
        }
        if((f1==false && m2.size()<3) || (f2==false && m1.size()<3)){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        
    }
    return 0;
}