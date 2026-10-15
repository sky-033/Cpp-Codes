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
        lli n,q;
        cin>>n>>q;
        vll a(n),preSum(n);
        f(i,n) cin>>a[i];
        preSum[0]=a[0];
        for(lli i=1;i<n;i++){
            preSum[i]=preSum[i-1]+a[i];
        }
        f(i,q) {
            lli sum=0;
            lli l,r,k;
            cin>>l>>r>>k;
            if(l==1) sum=preSum[n-1]-preSum[r-1];
            else sum=preSum[n-1]-preSum[r-1]+preSum[l-2];
            sum+=(r-l+1)*k;
            if(sum%2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        } 
    }
    return 0;
}