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
lli gcd(lli a,lli b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n),b;
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end());
        lli mini=a[0];
        ff(1,n,1){
            if(a[i]%mini==0){
                b.push_back(a[i]);
            }
        }
        lli size=b.size();
        if(size==0) cout<<"NO"<<endl;
        else{
            lli ans=b[0];
            ff(1,size,1){
                ans=gcd(b[i],ans);
            }
            if(ans==mini) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}