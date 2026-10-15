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

lli find(vll &b,lli x){
    lli n=b.size();
    lli l=0,h=n-1,mid;
    while(h-l>1){
        mid=(l+h)/2;
        if(b[mid]>x) h=mid;
        else l=mid;
    }
    if(x<=b[l]) return l+1;
    else return h+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    vll a(n),b(n);
    f(i,n){
        cin>>a[i];
    }
    b[0]=a[0];
    ff(1,n,1){
        b[i]=b[i-1]+a[i];
    }
    lli m;
    cin>>m;
    vll q(m);
    f(i,m) cin>>q[i];
    f(i,m){
        lli ans=find(b,q[i]);
        cout<<ans<<" ";  
    }
    cout<<endl;
    return 0;
}