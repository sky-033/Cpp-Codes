#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_map<int,int> mp;
        set<int> multi,zero;
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        sort(a.begin(),a.end());
        if(mp[0]==0) cout<<0<<endl;
        else{
            for(auto &it: mp){
                if(it.second>=2){
                    multi.insert(it.first);
                }
            }
            for(int i=1;i<a[n-1];i++){
                if(mp[i]==0) zero.insert(i);
            }
            for(auto &it:multi){
                
            }
            
        }   
    }
    return 0;
}