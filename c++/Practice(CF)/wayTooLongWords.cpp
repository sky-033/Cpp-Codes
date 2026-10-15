#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int n=s.size();
        int N=n;
        if(n<=10) cout<<s<<endl;
        else{
            n=n-2;
            cout<<s[0]+to_string(n)+s[N-1]<<endl;
        }
    }
    return 0;
}