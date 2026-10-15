#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int N=n;
        int c=0;
        while(n>0){
            c++;
            n/=10;
        }
        if(c==1){ cout<<N<<endl;
        c=0;}
        else if(c==2) {cout<<9+N/10<<endl;
        c=0;}
        else if(c==3){ cout<<18+N/100<<endl;
        c=0;}
        else if(c==4){
            cout<<27+N/1000<<endl;
            c=0;
        } 
        else if(c==5){
             cout<<36+N/10000<<endl;
             c=0;
        }
        else if(c==6){
            cout<<45+N/100000<<endl;
            c=0;
        }
        // else{
        //     cout<<54+N/1000000<<endl;
        // }

    }
    return 0;
}