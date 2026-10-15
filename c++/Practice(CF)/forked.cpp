// #include<bits/stdc++.h>
// using namespace std;
// typedef long long int lli; 

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         lli a,b;
//         cin>>a>>b;
//         lli xk,yk,xq,yq;
//         cin>>xk>>yk;
//         cin>>xq>>yq;
//         int c=0,ct=0;
//         lli x1,x2,x3,x4,y1,y2,y3,y4;
//         x1=xk+a;
//         y1=yk+b;
//         x2=xk+a;
//         y2=yk-b;
//         x3=xk-a;
//         y3=yk+b;
//         x4=xk-a;
//         y4=yk-b;
//         lli a1,a2,a3,a4,b1,b2,b3,b4;
//         a1=xq+a;
//         b1=yq+b;
//         a2=xq+a;
//         b2=yq-b;
//         a3=xq-a;
//         b3=yq+b;
//         a4=xq-a;
//         b4=yq-b;
//         if(a!=b){
//             if(((x1==a1 && y1==b1) || (x1==a2 && y1==b2) || (x1==a3 && y1==b3) || (x1==a4 && y1==b4)) || ((y1==a1 && x1==b1) || (y1==a2 && x1==b2) || (y1==a3 && x1==b3) || (y1==a4 && x1==b4))) ct+=2;
//             if(((x2==a1 && y2==b1) || (x2==a2 && y2==b2) || (x2==a3 && y2==b3) || (x2==a4 && y2==b4)) || ((y2==a1 && x2==b1) || (y2==a2 && x2==b2) || (y2==a3 && x2==b3) || (y2==a4 && x2==b4))) ct+=2;
//             if(((x3==a1 && y3==b1) || (x3==a2 && y3==b2) || (x3==a3 && y3==b3) || (x3==a4 && y3==b4)) || ((y3==a1 && x3==b1) || (y3==a2 && x3==b2) || (y3==a3 && x3==b3) || (y3==a4 && x3==b4))) ct+=2;
//             if(((x4==a1 && y4==b1) || (x4==a2 && y4==b2) || (x4==a3 && y4==b3) || (x4==a4 && y4==b4)) || ((y4==a1 && x4==b1) || (y4==a2 && x4==b2) || (y4==a3 && x4==b3) || (y4==a4 && x4==b4))) ct+=2;
//             cout<<ct<<endl;
//         }
//         else{
//             if((x1==a1 && y1==b1) || (x1==a2 && y1==b2) || (x1==a3 && y1==b3) || (x1==a4 && y1==b4)) c++;
//             if((x2==a1 && y2==b1) || (x2==a2 && y2==b2) || (x2==a3 && y2==b3) || (x2==a4 && y2==b4)) c++;
//             if((x3==a1 && y3==b1) || (x3==a2 && y3==b2) || (x3==a3 && y3==b3) || (x3==a4 && y3==b4)) c++;
//             if((x4==a1 && y4==b1) || (x4==a2 && y4==b2) || (x4==a3 && y4==b3) || (x4==a4 && y4==b4)) c++;
//             cout<<c<<endl;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 
int dx[4]={1,1,-1,-1},dy[4]={1,-1,1,-1};
int main(){
    int t;
    cin>>t;
    while(t--){
        lli a,b;
        cin>>a>>b;
        lli xk,yk,xq,yq;
        cin>>xk>>yk;
        cin>>xq>>yq;
        set<pair<int,int>> kingHits,queenHits;
        for(int i=0;i<4;i++){
            kingHits.insert({xk+dx[i]*a,yk+dy[i]*b});
            kingHits.insert({xk+dx[i]*b,yk+dy[i]*a});
            queenHits.insert({xq+dx[i]*a,yq+dy[i]*b});
            queenHits.insert({xq+dx[i]*b,yq+dy[i]*a});
        }
        int c=0;
        for(auto it:kingHits){
            if(queenHits.find(it)!=queenHits.end()) c++;
        }
        cout<<c<<endl;
    }
    return 0;
}