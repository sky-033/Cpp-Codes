#include<bits/stdc++.h>
using namespace std;

vector<int> ans(4);
vector<int> p={4,8,15,16,23,42};
vector<int> p1(6,0);
vector<pair<int,pair<int,int>>> mult;
int main(){
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            mult.push_back({p[i]*p[j],{i+1,j+1}});
        }
    }
    sort(mult.begin(),mult.end());
    for(int i=0;i<2;i++){
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        cout.flush();
        cin>>ans[i];
    }
    for(int i=3;i<5;i++){
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        cout.flush();
        cin>>ans[i-1];
    }
    bool flag1=false,flag2=false;
    int i1,i2,i3,i4;
    int a1=ans[0];
    int a2=ans[1];
    for(auto it:mult){
        if(it.first==a1 && !flag1){
            i1=it.second.first;
            i2=it.second.second;
            flag1=true;
        }
        if(it.first==a2 && !flag2){
            i3=it.second.first;
            i4=it.second.second;
            flag2=true;
        }
        if(flag1 && flag2) break;
    }
    if(i1==i3){
        p1[1]=p[i1-1];
        p1[0]=p[i2-1];
        p1[2]=p[i4-1];
    }
    else if(i1==i4){
        p1[1]=p[i1-1];
        p1[0]=p[i2-1];
        p1[2]=p[i3-1];
    }
    else if(i2==i3){
        p1[1]=p[i2-1];
        p1[0]=p[i1-1];
        p1[2]=p[i4-1];
    }
    else{
        p1[1]=p[i2-1];
        p1[0]=p[i1-1];
        p1[2]=p[i3-1];
    }
    
    flag1=false,flag2=false;
    int i11,i22,i33,i44;
    int a11=ans[2];
    int a22=ans[3];
    for(auto it:mult){
        if(it.first==a11 && !flag1){
            i11=it.second.first;
            i22=it.second.second;
            flag1=true;
        }
        if(it.first==a22 && !flag2){
            i33=it.second.first;
            i44=it.second.second;
            flag2=true;
        }
        if(flag1 && flag2) break;
    }
    if(i11==i33){
        p1[4]=p[i11-1];
        p1[3]=p[i22-1];
        p1[5]=p[i44-1];
    }
    else if(i11==i44){
        p1[4]=p[i11-1];
        p1[3]=p[i22-1];
        p1[5]=p[i33-1];
    }
    else if(i22==i33){
        p1[4]=p[i22-1];
        p1[3]=p[i11-1];
        p1[5]=p[i44-1];
    }
    else{
        p1[4]=p[i22-1];
        p1[3]=p[i11-1];
        p1[5]=p[i33-1];
    }
    cout<<"!";
    for(int i=0;i<6;i++){
        cout<<" "<<p1[i];
    }
    cout<<endl;
    cout.flush();
    return 0;
}