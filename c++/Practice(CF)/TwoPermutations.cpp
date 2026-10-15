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
        lli n,a,b;
        cin>>n>>a>>b;
        if(a==b && n==a) cout<<"YES"<<endl;
        else if(n-(a+b)<=1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}