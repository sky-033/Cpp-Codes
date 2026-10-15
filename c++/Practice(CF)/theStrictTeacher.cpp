#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        vector<int> b(m),a(q);
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        for(int i=0;i<q;i++){
            cin>>a[i];
        }
        int a1=(a[0]-b[0]);
        int a2=(a[0]-b[1]);
        if(a2>0){
            cout<<n-b[1]<<endl;
        }
        else if(a1<0){
            cout<<b[0]-1<<endl;
        }
        else{
            cout<<(b[1]-b[0])/2<<endl;
        }
    }
    return 0;
}