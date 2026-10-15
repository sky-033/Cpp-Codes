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
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        lli l=0,r=0,maxlen=-1e18;
        while(r<n){
            if(a[r]==0){
                r++;
            }
            else{
                r++;
                l=r;
            }
            maxlen=max(maxlen,r-l);
        }
        cout<<maxlen<<endl;
    }
    return 0;
}