#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
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
        lli sum_odd=0,sum_even=0,ct_even=0,ct_odd=0;
        ff(0,n,2){
            sum_even+=a[i];
        }
        ff(1,n,2){
            sum_odd+=a[i];
        }
        ct_even=n/2,ct_odd=n/2;
        if(n%2!=0){
            ct_even++;
        }
        if(sum_even%ct_even!=0 || sum_odd%ct_odd!=0){
            cout<<"NO"<<endl;
        }
        else{
            lli a=sum_even/ct_even;
            lli b=sum_odd/ct_odd;
            if(a==b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}