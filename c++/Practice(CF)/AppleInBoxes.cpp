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
        lli n,k;
        cin>>n>>k;
        vll a(n);
        f(i,n) cin>>a[i];
        lli mini=1e18,maxi=-1e18,sum=0;
        f(i,n){
            maxi=max(maxi,a[i]);
            mini=min(mini,a[i]);
            sum+=a[i];
        }
        lli ct=0;
        f(i,n){
            if(a[i]==maxi) ct++;
        }
        if(maxi-mini-1>k || (maxi-mini-1==k && ct>=2)) cout<<"Jerry"<<endl;
        else{
            if(sum%2==0) cout<<"Jerry"<<endl;
            else cout<<"Tom"<<endl;
        }
    }
    return 0;
}