#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        string s,rev_s;
        cin>>s;
        rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        if(k==0){
            if(s<rev_s) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            bool flag=false;
            f(i,n-1){
                if(s[i]!=s[i+1]){
                    flag=true;
                    break;
                }
            }
            if(flag==true) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}