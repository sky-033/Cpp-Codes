#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int right[n],up[n];
        for(int i=0;i<n;i++){
            cin>>right[i]>>up[i];
        }
        int i_rt=right[0],i_upp=up[0];
        int rt=m,upp=m;
        for(int i=0;i<n;i++){
            rt+=right[i];
            upp+=up[i];
        }
        cout<<2*((rt-i_rt)+(upp-i_upp))<<endl;
    }
    return 0;
}