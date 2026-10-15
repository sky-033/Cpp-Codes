#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    string s;
    getline(cin,s);
    int e=0,d=0,d1=0,c1=0,c2=0,c3=0,s1=0,s2=0,total=0;
    for(int i=0;i<n;i++){
        if(isupper(s[i])){
            c1++;
        }
        else if(islower(s[i])){
            c2++;
        }
        else if(isdigit(s[i])){
            d++;
        }
        else if(s[i]==' '){
            e++;
        }
    }
    cout<<c1<<c2<<d<<e<<endl;
    if(c1+c2+d+e==n){
        c3++;
    }
    if(c1==0){
        s1++;
    }
    if(c2==0){
        s2++;
    }
    if(d==0){
        d1++;
    }
    int three=s1+s2+d1+c3;
    cout<<s1<<s2<<d1<<c3<<three<<endl;
    if(n<6){
        n+=three;
        total+=(6-n);
    }
    else{
        total+=three;
    }
    cout<<total;
}