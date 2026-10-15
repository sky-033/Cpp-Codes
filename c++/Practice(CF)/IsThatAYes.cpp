#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(isupper(s[i])){
                s[i]=tolower(s[i]);
            }
        }
        
        if(s[0]=='y' && s[1]=='e' && s[2]=='s') cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}