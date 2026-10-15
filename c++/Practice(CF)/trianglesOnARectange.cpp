#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli w,h;
        cin>>w>>h;
        lli k1,k2,l1,l2;
        cin>>k1;
        vll a(k1);
        f(i,k1) cin>>a[i];
        cin>>k2;
        vll b(k2);
        f(i,k2) cin>>b[i];
        cin>>l1;
        vll c(l1);
        f(i,l1) cin>>c[i];
        cin>>l2;
        vll d(l2);
        f(i,l2) cin>>d[i];
        lli maxi=-1e18;
        lli A1,A2,A3,A4;
        A1=h*(a[k1-1]-a[0]);
        maxi=max(maxi,A1);
        A2=h*(b[k2-1]-b[0]);
        maxi=max(maxi,A2);
        A3=w*(c[l1-1]-c[0]);
        maxi=max(maxi,A3);
        A4=w*(d[l2-1]-d[0]);
        maxi=max(maxi,A4);
        cout<<maxi<<endl;
    }
    return 0;
}