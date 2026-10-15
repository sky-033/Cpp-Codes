#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                char ch;
                cin>>ch;
                if(ch=='#') arr[i]=j+1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[n-i-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}