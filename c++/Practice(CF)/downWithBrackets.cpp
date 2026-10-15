#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        lli n=s.size();
        lli ct=0,i=0;
        bool flag=true;
        while(i<n-1){
            if(s[i]=='(') ct++;
            else ct--;
            if(ct==0){
                flag=false;
                break;
            }
        }
        if(s[n-1]==')' && flag==true) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}