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
        lli n,k,p;
        cin>>n>>k>>p;
        lli maxi=n*p;
        lli mini=maxi*-1;
        k=abs(k);
        if(k>maxi || (-1*k)<mini) cout<<-1<<endl;
        else{
            lli ans=k/p;
            if(k%p!=0) ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}