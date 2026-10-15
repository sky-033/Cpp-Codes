#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 
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
        vll p(n);
        f(i,n){
            cin>>p[i];
        }
        lli mini=0;
        f(i,n){
            if((i+1)!=p[i]) mini=gcd(mini,abs(i+1-p[i]));
        }
        cout<<mini<<endl;
    }
    return 0;
}