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
bool check(lli num){
    lli N=num;
    while(num>0){
        lli rem=num%10;
        if(rem!=0 && N%rem!=0) return false;
        num/=10;
    }
    return true;
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
        bool flag=false;
        lli ans=-1;
        for(lli i=n;i<=1e18;i++){
            if(check(i)){
                flag=true;
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}