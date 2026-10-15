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
        lli x,n,ans;
        cin>>x>>n;
        if(x%2==0){
            if(n%2==0){
                if(n/2 %2==1) {
                    ans=x+1;
                    cout<<ans<<endl;
                }
                else{
                    ans=x;
                    cout<<ans<<endl;
                }
            }
            else{
                if((n-2)%4==0 || (n-3)%4==0){
                    ans=x+1+n;
                    cout<<ans<<endl;
                }
                else{
                    ans=x-n;
                    cout<<ans<<endl;
                }
            }
        }
        else{
            if(n%2==0){
                if(n/2 %2==1) {
                    ans=x-1;
                    cout<<ans<<endl;
                }
                else{
                    ans=x;
                    cout<<ans<<endl;
                }
            }
            else{
                if((n-2)%4==0 || (n-3)%4==0){
                    ans=x-1-n;
                    cout<<ans<<endl;
                }
                else{
                    ans=x+n;
                    cout<<ans<<endl;
                }
            }
        }
    }
    return 0;
}