#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli w,h,a,b;
        cin>>w>>h>>a>>b;
        lli x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        lli ax=x1,ay=y1;
        lli bx=x1+a,by=y1;
        lli cx=x1+a,cy=y1+b;
        lli dx=x1,dy=y1+b;
        lli a1x=x2,a1y=y2;
        lli b1x=x2+a,b1y=y2;
        lli c1x=x2+a,c1y=y2+b;
        lli d1x=x2,d1y=y2+b;
        bool flag=true;
        if(bx<=a1x && abs(cy-c1y)<b){
            lli hori=abs(a1x-bx);
            if(hori%a!=0) flag=false;
        }
        if(ax>=b1x && abs(cy-c1y)<b){
            lli hori=abs(ax-b1x);
            if(hori%a!=0) flag=false;
        }
        if(cy<=a1y && abs(ax-a1x)<a){
            lli verti=abs(a1y-cy);
            if(verti%b!=0) flag=false;
        }
        if(by>=d1y && abs(ax-a1x)<a){
            lli verti=abs(by-d1y);
            if(verti%b!=0) flag=false;
        }
        if(abs(ax-a1x)>a && abs(cy-c1y)>b){
            lli verti=min(abs(a1y-cy),abs(by-d1y));
            lli hori=min(abs(ax-b1x),abs(ax-b1x));
            if(hori%a!=0 && verti%b!=0) flag=false;
        }
        cout<<(flag? "YES":"NO")<<endl;
    }
    return 0;
}