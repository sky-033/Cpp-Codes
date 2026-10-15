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
        lli n,m;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;
        lli c=0;
        f(i,6){
            if(x.find(s)!=string::npos){
                cout<<c<<endl;
                break;
            }
            x+=x;
            c++;
        }
        if(x.find(s)==string::npos) cout<<-1<<endl;
    }
    return 0;
}