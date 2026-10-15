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
        lli n,a,b,c;
        cin>>n>>a>>b>>c;
        lli A=a,B=a+b,C=a+b+c;
        lli ans=n-C;
        lli d=C;
        if(ans%d==0){
            ans/=d;
            ans++;
        }
        else{
            ans/=d;
            ans+=2;
        }
        lli x=A+(ans-1)*d;
        lli y=B+(ans-1)*d;
        lli z=C+(ans-1)*d;
        
        lli days=0;
        if(n<=d){
            if(n<=x){
                days=1;
            }
            else if(n<=y){
                days=2;
            }
            else{
                days=3;
            }
        }
        else{
            if(n<=x){
            days=(x-A)/d;
            days*=3;
            days+=1;
        }
        else if(n<=y){
            days=(y-B)/d;
            days*=3;
            days+=2;
        }
        else{
            days=(z-C)/d;
            days*=3;
            days+=3;
        }
        }
        cout<<days<<endl;
    }
    return 0;
}