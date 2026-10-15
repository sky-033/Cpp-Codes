#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        int check=min(a[0],b[0]-a[0]);
        bool flag=true;
        for(int i=1;i<n;i++){
            if(check<=a[i] && check<=b[0]-a[i]){
                check=min(a[i],b[0]-a[i]);
            }
            else if(check<=a[i]) check=a[i];
            else if(check<=b[0]-a[i]) check=b[0]-a[i];
            else{
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}