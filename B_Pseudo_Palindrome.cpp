#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> arr(n),marked(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool flag=true;
        sort(arr.begin(),arr.end());
        if(n%2==0){
            for(int i=0;i<n-1;i++){
                if(!marked[i] && !marked[i+1]){
                    if(arr[i+1]-arr[i]<=d){
                        marked[i]=1;
                        marked[i+1]=1;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
        }
        else{
            int ct=0;
            for(int i=0;i<n-1;i++){
                if(!marked[i] && !marked[i+1]){
                    if(arr[i+1]-arr[i]<=d){
                        marked[i]=1;
                        marked[i+1]=1;
                    }
                    else if(ct==1){
                        flag=false;
                        break;
                    }
                    else ct++;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}