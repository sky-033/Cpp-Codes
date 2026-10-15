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
        lli n,x;
        cin>>n>>x;
        vll a(n);
        f(i,n) cin>>a[i];
        lli ct=0,ans=0,sum=0;
        f(i,n){
            sum+=a[i];
            if(a[i]%x!=0){
                ans+=a[i]/x +1;
            }
            else ans+=a[i]/x;
        }
        lli maxi=ans;
        lli mini=sum/x;
        if(sum%x!=0) mini++;
        cout<<mini<<" "<<maxi<<endl;
    }
    return 0;
}