#include<bits/stdc++.h>
using namespace std;
#define lli long long 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli a,x,y;
        cin>>a>>x>>y;
        if(x>y) swap(x,y);
        if(a>x && a<y) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
    return 0;
}