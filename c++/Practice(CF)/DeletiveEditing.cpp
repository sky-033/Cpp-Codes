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
    int n;
    cin>>n;
    while(n--){
        string s,t;
        cin>>s>>t;
        vll v(26,0);
        f(i,t.size()){
            v[t[i]-'A']++;
        }
        for(lli i=s.size()-1;i>=0;i--){
            if(v[s[i]-'A']>0) v[s[i]-'A']--;
            else s[i]='#';
        }
        string temp="";
        f(i,s.size()){
            if(s[i]!='#') temp+=s[i];
        }
        if(temp==t) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}