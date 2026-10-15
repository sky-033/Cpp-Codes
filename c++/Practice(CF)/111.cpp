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
        lli n,ct=0;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        f(i,n){
            while(a[i]%2==0){
                a[i]/=2;
                ct++;
            }
        }
        sort(a.begin(),a.end());
        a[n-1]=pow(2,ct)*a[n-1];
        lli sum=0;
        f(i,n){
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}