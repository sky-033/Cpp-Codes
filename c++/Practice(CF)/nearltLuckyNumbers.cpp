#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    lli n;
    cin>>n;
    int ct=0;
    while(n>0){
        int rem=n%10;
        if(rem==4 || rem==7) ct++;
        n/=10;
    }
    if(ct==4 || ct==7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}