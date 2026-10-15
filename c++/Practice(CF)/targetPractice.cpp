#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    int t;
    cin>>t;
    while(t--){
        int ct=0;
        char arr[10][10];
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(arr[i][j]=='X'){
                    if(i==0 || i==9 || j==0 || j==9) ct+=1;
                    else if(i==1 || i==8 || j==1 || j==8) ct+=2;
                    else if(i==2 || i==7 || j==2 || j==7) ct+=3;
                    else if(i==3 || i==6 || j==3 || j==6) ct+=4;
                    else  ct+=5;
                }
            } 
        }
        cout<<ct<<endl;
        
    }
    return 0;
}