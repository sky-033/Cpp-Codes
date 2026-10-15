#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int sum=0;
        for(int i=0;i<(r-l+1);i++){
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}