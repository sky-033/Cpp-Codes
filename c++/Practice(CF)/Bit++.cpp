#include<bits/stdc++.h>
using namespace std;

int main(){
    int x=0;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="++X" || s=="X++") x++;
        else x--; 
    }
    cout<<x<<endl;
    return 0;
}