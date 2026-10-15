#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n;
    cin>>n;
    int P1,P2,P3,T1,T2;
    cin>>P1>>P2>>P3>>T1>>T2;
    vector<pair<int,int>> v(n);
    lli total=0;
    for(auto &it:v){
        cin>>it.first>>it.second;
    }
    for(int i=0;i<n-1;i++){
        lli l=v[i].first, r=v[i].second;
        lli x=v[i+1].first-r;
        if(x<=T1) total+=x*P1;
        else if(x>T1 && x<=(T1+T2)) total+=P1*T1+P2*(x-T1);
        else total+=P1*T1+P2*T2+P3*(x-(T1+T2));
    }
    for(auto &it:v){
        total+=P1*(it.second-it.first);
    }
    cout<<total<<endl;
    return 0;
}