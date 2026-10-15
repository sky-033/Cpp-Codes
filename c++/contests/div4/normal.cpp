#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a,b;
        cin>>a;
        int n=a.size();
        b.resize(n);
        for(int i=n-1;i>=0;i--){
            if(a[i]=='p') b[n-i-1]='q';
            else if(a[i]=='q') b[n-i-1]='p';
            else b[n-i-1]='w';
        }
        cout<<b<<endl;
    }
}