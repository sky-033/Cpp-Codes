#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        vll a,b;
        f(i,n){
            if(s[i]=='A') a.push_back(i+1);
            else b.push_back(i+1);
        }
        lli a1=a.size(),b1=b.size();
        if(a[0]==1 && a[a1-1]==n) cout<<"Alice"<<endl;
        else if(b[0]==1 && b[b1-1]==n) cout<<"Bob"<<endl;
        else if(n==2){
            if(a[0]==1) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else if(a[0]==1){
            if(b1==1) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else if(a[a1-1]==n){
            if(a1>1 && b1>=1){
                if(a[a1-2]>b[b1-1]) cout<<"Alice"<<endl;
                else cout<<"Bob"<<endl;
            }
            else cout<<"Bob"<<endl;
        }
    }
    return 0;
}