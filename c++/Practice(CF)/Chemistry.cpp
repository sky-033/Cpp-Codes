#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int arr[26]={0};
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int c=0;
        if(n-k==1){
            cout<<"YES"<<endl;
            // c=0;
        }
        else{
            
                
                for(int j=0;j<26;j++){
                    if(arr[j]%2!=0) c++;
                }
                if(c>k+1){
                    cout<<"NO"<<endl;
                    c=0;
                }
                else {
                    cout<<"YES"<<endl;
                    c=0;
                }
            
        }
       
    }
    return 0;
}