#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<1+max(m,n)<<endl;
    }
    return 0;
}