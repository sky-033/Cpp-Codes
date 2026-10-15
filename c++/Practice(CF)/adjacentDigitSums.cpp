#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        bool flag=true;
        if(y==x+1){
            flag=true;
        }
        else if((x-y+1)>=0 && (x-y+1)%9==0){
            flag=true;
        }
        else{
            flag=false;
        }
        cout<<(flag? "YES":"NO")<<endl;
    }
    return 0;
}