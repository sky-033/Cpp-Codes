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
        lli ct0=0,ct1=0;
        bool flag=false;
        f(i,n){
            cin>>a[i];
            if(a[i]==1){
                flag=true;
                ct1++;
            }
            if(a[i]==0) ct0++;
        }
        if(flag){
            lli ans=pow(2,ct0)*ct1;
            cout<<ans<<endl;
        }
        else cout<<0<<endl;

    }
    return 0;
}