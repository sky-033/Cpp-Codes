#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 
lli gcd(lli a, lli b){
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
        vll a(n);
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end());
        lli mini=1e18;
        for(lli i=0;i<n;i++){
            for(lli j=i+1;j<n;j++){
                lli rem=a[j]%a[i];
                if(rem==0) mini=min(mini,a[i]);
                else{
                    if(a[j]%rem==0 && a[i]%rem==0) mini=min(mini,rem);
                    else{
                        mini=min(mini,gcd(a[i],a[j]));
                    }
                }
            }
        }
        if(mini<=2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}