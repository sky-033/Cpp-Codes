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

const lli M=1e9+7; 

bool feasible(lli T,vll &A,vll &B){
    lli N=A.size();
    __int128 jagah=0;  
    __int128 req=0; 
    f(i,N){
        lli c=T-A[i];             
        if(c<0) return false;  
        lli s=min(B[i],c);
        lli cadd=B[i]-s;
        lli left=c-s;
        jagah+=left/2;
        req+=cadd;
    }
    return (jagah-req)>=0;
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
        vll A(n),B(n);
        lli l=0,h=0;
        f(i,n){
            cin>>A[i];
            l=max(l,A[i]);
        }
        f(i,n){
            cin>>B[i];
            h+=2*B[i];
        }
        h+=l;
        while(l<h){
            lli mid=(l+h)/2;
            if(feasible(mid,A,B)) h=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}