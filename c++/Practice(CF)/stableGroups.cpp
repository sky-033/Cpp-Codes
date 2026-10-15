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
    lli n,k,x;
    cin>>n>>k>>x;
    vll a(n);
    f(i,n) cin>>a[i];
    sor(a);
    vll diff;
    ff(1,n,1){
        if(a[i]-a[i-1]>x) diff.push_back(a[i]-a[i-1]);
    }
    sor(diff);
    lli ans=0;
    fa(diff){
        it=(it+x-1)/x -1;
    }
    lli size=diff.size();
    if(size>0){
        lli ct=0;
        vll prefix(size);
        prefix[0]=diff[0];
        ff(1,size,1) prefix[i]=prefix[i-1]+diff[i];
        f(i,size){
            if(prefix[i]<=k) ct++;
            else break;
        }
        ans=ct;
    }
    lli left=size-ans;
    cout<<left+1<<endl;
    return 0;
}