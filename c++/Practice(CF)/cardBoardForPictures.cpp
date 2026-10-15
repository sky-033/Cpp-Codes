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

bool check(vll &s,lli n,lli mid,lli c){
    lli area=0;
    f(i,n){
        area+=(s[i]+2*mid)*(s[i]+2*mid);
        if(area>=c) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,c;
        cin>>n>>c;
        vll s(n);
        f(i,n) cin>>s[i];
        lli l=0,h=1e9,mid;
        //FFFFTTTTT.....
        while(h-l>1){
            mid=(l+h)>>1;
            if(check(s,n,mid,c)) h=mid;
            else l=mid+1;
        }
        if(check(s,n,l,c)) cout<<l<<endl;
        else cout<<h<<endl;
    }
    return 0;
}