#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    string s;
    cin>>s;
    int l=0,u=0;
    for(auto &it:s){
        if(islower(it)) l++;
        else u++;
    }
    if(l>=u){
        for(auto &it:s){
            if(islower(it)) cout<<it;
            else cout<<char(it+32);
        }
    }
    else{
        for(auto &it:s){
            if(islower(it)) cout<<char(it-32);
            else cout<<it;
        }
    }
    return 0;
}