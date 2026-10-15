#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int diff[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        bool flag=true;
        int sum1=0,sum2=0;
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum1+=a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            sum2+=b[i];
        }
        int c=0;
        for(int i=0;i<n;i++){
            diff[i]=a[i]-b[i];
            if(diff[i]<=0) c++;
        }
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(diff[i]<min) min=diff[i];
        }
        for(int i=0;i<n;i++){
            if((min*-1)-diff[i]>1) flag=false;
        }
        cout<<min<<endl;
        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        // if(sum1==0 && sum2==0){
        //     cout<<"YES"<<endl;
        // }
        // else if(c>1) cout<<"NO"<<endl;
        // else cout<<"YES"<<endl;  
    }
    return 0;
}