#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maxi=max(2*(x-a[n-1]),a[0]);
        for(int i=0;i<n-1;i++){
            maxi=max(a[i+1]-a[i],maxi);
        }
        cout<<maxi<<endl;
    }
    return 0;
}