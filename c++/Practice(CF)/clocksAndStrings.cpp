#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        if(c>a && c<b){
            if(d>b || (d<a)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            if(d>a && d<b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}