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
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m,k;
        cin>>n>>m>>k;
        vll a(m),q(k),hsh(n+1,0);
        f(i,m){
            cin>>a[i];
        }
        f(i,k){
            cin>>q[i];
            hsh[q[i]]++;
        }
        string ans="";
        if(n-k>=2){
            f(i,m){
                ans+='0';
            }
            
        }
        else if(n-k==0){
            f(i,m){
                ans+='1';
            }
            
        }
        else{
            f(i,m){
                if(hsh[a[i]]==0) ans+='1';
                else ans+='0';
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}