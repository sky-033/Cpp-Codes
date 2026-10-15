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
        lli n,ans=0;;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        ff(i,0,n-1){
            ans=a[i]^a[i+1];
        }
        if(n%2){
            lli x=-1;
            bool flag=false;
            f(i,pow(2,8)){
                if(ans^i==0){
                    x=i;
                    flag=true;
                    break;
                }
            }
            if(flag) cout<<x<<endl;
            else cout<<-1<<endl; 
        }
        else cout<<ans<<endl;
    }
    return 0;
}