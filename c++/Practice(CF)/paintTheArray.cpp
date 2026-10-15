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
        f(i,n) cin>>a[i];
        lli gcd1=a[0],gcd2=a[1];
        ff(0,n,2){
            gcd1=__gcd(gcd1,a[i]);
        }
        ff(1,n,2){
            gcd2=__gcd(gcd2,a[i]);
        }
        bool flag1=true,flag2=true;
        ff(0,n,2){
            if(a[i]%gcd2==0){
                flag2=false;
            }
        }
        ff(1,n,2){
            if(a[i]%gcd1==0){
                flag1=false;
            }
        }
        if(flag1==false && flag2==false) cout<<0<<endl;
        else if(flag1==true) cout<<gcd1<<endl;
        else cout<<gcd2<<endl;
    }
    return 0;
}