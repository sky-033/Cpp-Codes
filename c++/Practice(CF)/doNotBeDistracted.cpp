#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int hsh[26]={0};
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<int> st;
        bool flag=true;
        for(int i=0;i<n-1;i++){
            st.push(s[i]-'A');
            hsh[s[i]-'A']++;
            if((s[i+1]-'A')!=st.top() && hsh[s[i+1]-'A']!=0){
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
        }
        if(flag==true) cout<<"YES"<<endl;
    }
    return 0;
}