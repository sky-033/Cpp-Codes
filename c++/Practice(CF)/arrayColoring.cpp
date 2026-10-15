#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int c_odd=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]&1) c_odd++;
        }
        // cout<<c_even<<" "<<c_odd;
        if(c_odd%2!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}