#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][3];
    int sum[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            sum[i]+=arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(sum[i]>=2) cnt++;
    }
    cout<<cnt;
    return 0;
}