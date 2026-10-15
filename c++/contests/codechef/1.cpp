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
        lli n,m,k;
        cin>>n>>m>>k;
        lli a1=k/n,a2=k%n;
        lli b1=k/m,b2=k%m;
        lli ans1=0,ans2=0;
        if(a2!=0){
            a1++;
            ans1=n*(m-a1);
        }
        else{
            ans1=n*(m-a1);
        }
        if(b2!=0){
            b1++;
            ans2=m*(n-b1);
        }
        else{
            ans2=m*(n-b1);
        }
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}