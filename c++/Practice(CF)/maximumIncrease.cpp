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
    int maxi=0,ct=1;
    for(int i=0;i<n-1;i++){
        if(a[i]<a[i+1]){
            ct++;
        }
        else{
            maxi=max(maxi,ct);
            ct=1;
        }
    }
    maxi=max(maxi,ct);
    cout<<maxi<<endl;
    return 0;
}