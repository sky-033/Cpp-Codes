#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,m;
        cin>>n>>s>>m;
        vector<pair<int,int>> interval(n);
        for(auto &it:interval){
            cin>>it.first>>it.second;
        }
        bool flag=false;
        if(interval[0].first>=s){
            flag=true;
        }
        if(m-interval[n-1].second>=s){
            flag=true;
        }
        for(int i=0;i<n-1;i++){
            if(interval[i+1].first-interval[i].second>=s){
                flag=true;
                break;
            }
        }
        if(flag==false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
    return 0;
}