#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int arr[4];
        for(int i=0;i<4;i++){
            cin>>arr[i];
        }
        int x=arr[3]-arr[2];
        int y=arr[2]-arr[1];
        int z=arr[0]+arr[1];
        if(x==y && y==z){
            cout<<3<<endl;
        }
        else if(x==y && x!=z){
            cout<<2<<endl;
        }
        else if(x==z && x!=y){
            cout<<2<<endl;
        }
        else if(y==z && y!=x){
            cout<<2<<endl;
        } 
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}