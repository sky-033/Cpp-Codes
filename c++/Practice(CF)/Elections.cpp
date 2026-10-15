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
        lli a,b,c;
        cin>>a>>b>>c;
        lli maxi=max(a,b);
        if(a==b && b==c){
            cout<<1<<" "<<1<<" "<<1<<endl;
        }
        else if(a==maxi){
            cout<<0<<" "<<maxi-b+1<<" "<<maxi-c+1<<endl;
        }
        else if(b==maxi){
            cout<<maxi-a+1<<" "<<0<<" "<<maxi-c+1<<endl;
        }
        else if(b==maxi){
            cout<<maxi-a+1<<" "<<maxi-b+1<<" "<<0<<endl;
        }
    }
    return 0;
}