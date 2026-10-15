#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff(a,b,c) for(ll i=a;i<b;i+=c)

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ff(1,n+1,2){
            cout<<i<<" ";
        }
        if(n%2==0){
            for(ll i=n;i>=2;i-=2){
                cout<<i<<" ";
            }
        }
        else{
            for(ll i=n-1;i>=2;i-=2){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}