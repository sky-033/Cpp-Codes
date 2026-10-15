#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(i,a,b) for(lli i=a;i<b;i++)
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
        lli ct0=0,ct1=0;
        f(i,n){
            if(s[i]==0) ct0++;
            else ct1++;
        }
        if(min(ct0,ct1)%2==0) cout<<"NET"<<endl;
        else cout<<"DA"<<endl;
    }
    return 0;
}