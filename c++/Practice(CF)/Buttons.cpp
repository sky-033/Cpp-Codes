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
        lli a,b,c;
        cin>>a>>b>>c;
        if(a==b){
            if(c%2==0) cout<<"Second"<<endl;
            else cout<<"First"<<endl;
        }
        else{
            if(a>b) cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }
    }
    return 0;
}