#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=n%10;
        n/=10;
        int b=n;
        cout<<a+b<<endl;
    }
    return 0;
}