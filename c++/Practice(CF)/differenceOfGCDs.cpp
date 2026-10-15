#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,l,r;
        cin>>n>>l>>r;
        lli mid=(l+r)/2;
        vll ans;
        bool flag=true;
        ff(1,n+1,1){
            lli a=mid/i;
            lli a1,a2;
            a1=abs(a+1),a2=abs(a-1);
            if(i*a1>=l && i*a1<=r) ans.push_back(i*a1);
            else if(i*a>=l && i*a<=r) ans.push_back(i*a);
            else if(i*a2>=l && i*a2<=r) ans.push_back(i*a2);
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            fa(ans) cout<<it<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}