#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            flag=false;
            break;
        }
    }
    if(flag) cout<<"Easy";
    else cout<<"Hard";
    return 0;
}