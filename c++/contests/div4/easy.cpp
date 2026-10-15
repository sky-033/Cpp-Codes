#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a=i;
            int b=n-i;
            if(a!=0 && b!=0 && a+b==n) c++;
        }
        cout<<c<<endl;
    }
    return 0;
}