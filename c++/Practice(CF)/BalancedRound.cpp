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
        lli n,k;
        cin>>n>>k;
        vll a(n);
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end());
        lli ct=0;
        lli l=0,h=1LL;
        while(h<n){
            if(a[h]-a[h-1]>k){
                l=h;
                h++;
                
            }
            else h++;
            ct=max(ct,h-l);
        }
        if(ct==0) cout<<0<<endl;
        else cout<<n-ct<<endl;
    }
    return 0;
}