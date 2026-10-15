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
        lli n,k;
        cin>>n>>k;
        string ch;
        cin>>ch;
        lli mini=INT_MAX;
        lli ct=0;
        f(i,k){
            if(ch[i]=='W') ct++;
        }
        mini=ct;
        lli i=k;
        for(lli i=k;i<n;i++){
            if(ch[i]=='W') ct++;
            if(ch[i-k]=='W') ct--;
            mini=min(mini,ct);
        }
        cout<<mini<<endl;
    }
    return 0;
}