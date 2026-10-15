#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
      int n;
      cin>>n;
      vector<int> a(n);
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      int ct=0;
      sort(a.begin(),a.end());
      for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            a[i+1]+=1;
            ct++;
        }
        else if(a[i]>a[i+1]){
            int temp=a[i]+1-a[i+1];
            a[i+1]=a[i]+1;
            ct+=temp;
        }
      }
      cout<<ct;
    return 0;
}

