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
        lli n,m;
        cin>>n>>m;
        vll w(m),l(m),h(m);
        f(i,m){
            cin>>w[i];
            cin>>l[i];
            cin>>h[i];
        }
        vll fiba(12);
        fiba[0]=0,fiba[1]=1,fiba[2]=2;
        ff(3,12,1){
            fiba[i]=fiba[i-1]+fiba[i-2];
        }
        lli size=fiba[n];
        string s="";
        f(i,m){
            bool flag=true;
            lli h1,w1,l1;
            if(h[i]>=w[i] && h[i]>=l[i]){
                h1=h[i];
                w1=w[i];
                l1=l[i];
            }
            else if(w[i]>=h[i] && w[i]>=l[i]){
                h1=w[i];
                w1=h[i];
                l1=l[i];
            }
            else{
                h1=l[i];
                w1=w[i];
                l1=h[i];
            }
            if(h1<fiba[n+1]) flag=false;
            if(w1<size) flag=false;
            if(l1<size) flag=false;
            
            if(flag) s.push_back('1');
            else s.push_back('0');
        }
        cout<<s<<endl;
    }
    return 0;
}