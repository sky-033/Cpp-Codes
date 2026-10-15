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
        lli a,b;
        cin>>a>>b;
        lli ans=30;
        f(i,30){
            lli A=a;
            lli B=b+i;
            if(B>1){
                lli ct=i;
                while(A>0){
                    A/=B;
                    ct++;
                }
                ans=min(ans,ct);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}