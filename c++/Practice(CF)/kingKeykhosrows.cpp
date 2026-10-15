#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int m=min(a,b);
        while(true){
            if(m%a==m%b) break;
            m++;
        }
        cout<<m<<endl;
    }
    return 0;
}