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
        lli x,y,k;
        cin>>x>>y>>k;
        lli temp=(k*(y+1)-1)/(x-1);
        if((k*(y+1)-1)%(x-1)!=0) temp++;
        cout<<temp+k<<endl;
    }
    return 0;
}