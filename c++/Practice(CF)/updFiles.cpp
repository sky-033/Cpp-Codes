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
        lli n,k;
        cin>>n>>k;
        if(k==1){
            cout<<(n-1)<<endl;
        }
        else if(k==2){
            if(n==2) cout<<1<<endl;
            else{
                lli a=(n-2)/2;
                if((n-2)%2!=0) a++;
                cout<<1+a<<endl;
            }
        }
        else{
            if(n==4) cout<<2<<endl;
            else{
                lli x=sqrt(k);
            x++;
            lli hrs=x;
            lli sum=1<<x;
            if(sum>=n) cout<<x<<endl;
            else{
                n-=sum;
                hrs+=n/k;
                if(n%k!=0) hrs++;
                cout<<hrs<<endl;
            }
            }
        }
    }
    return 0;
}