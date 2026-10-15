#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(s[i]==s[i+1]){
                flag=true;
                break;
            }
        }
        if(flag) cout<<1<<endl;
        else cout<<n<<endl;
    }
    return 0;
}