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
    // int t;
    // cin>>t;
    // while(t--){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        bool flag=false;
        ff(i,0,n-1){
            if(s[i]>s[i+1]){
                flag=true;
                cout<<"YES"<<endl;
                cout<<i+1<<" "<<i+2<<endl;
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
    // }
    return 0;
}