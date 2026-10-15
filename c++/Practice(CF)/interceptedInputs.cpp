#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        vector<int> a(k);
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        int K=k-2;
        sort(a.begin(),a.end());
        int l=0,r=k-1,x,y,ans=0;
        while(l<=r){
            ans=a[l]*a[r];
            if(ans==K){
                x=a[l];
                y=a[r];
                break;
            }
            else if(ans<K){
                l++;
            }
            else{
                r--;
            }
        }
        cout<<x<<" "<<y<<endl;
        
        
    }
    return 0;
}