#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_map<int,int> freq;
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        bool flag=true;
        if(freq.size()==1) cout<<"YES"<<endl;
        else if(freq.size()==2){
            for(auto &it:freq){
                if(!(it.second>=n/2 && it.second<=n/2 +1)){
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}