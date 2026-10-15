#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(i,a,b) for(lli i=a;i<b;i++)
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
        vll a(n*k);
        f(i,n*k) cin>>a[i];
        lli ct=k,sum=0;
        for(lli i=(n*k-n/2*1LL-1LL);i>=0;i-=(n/2+1)){
            sum+=a[i];
            ct--;
            if(ct==0) break;
        }
        cout<<sum<<endl;
    }
    return 0;
}