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
const lli M=1e9+7; 

bool check(vll &a, lli mid,lli x){
    lli ans=0;
    f(i,a.size()){
        if(mid>a[i]) ans+=(mid-a[i]);
    }
    return ans<=x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,x;
        cin>>n>>x;
        vll a(n);
        f(i,n) cin>>a[i];
        lli l=0,h=1e9,mid;
        while(h-l>1){
            mid=(l+h)/2;
            if(check(a,mid,x)) l=mid;
            else h=mid-1;
        }
        if(check(a,h,x)) cout<<h<<endl;
        else cout<<l<<endl;
    }
    return 0;
}