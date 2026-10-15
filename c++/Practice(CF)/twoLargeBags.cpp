#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        map<int,int> freq;
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        sort(a.begin(),a.end());
        bool flag=true;
        for(auto &it:freq){
            if(it.second%2!=0){
                flag=false;
            }
        }
        // if(n>2 && freq[a[0]]<2){
        //     flag=false;
        // }
        bool flag2=false;
        int temp=0;
        for(int i=0;i<n-1;i++){
            temp=max(a[i+1]-a[i],temp);
        }
        if((freq[a[0]]-1)/2 >= temp){
            flag2=true;
        }
        if(flag==true || flag2==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}