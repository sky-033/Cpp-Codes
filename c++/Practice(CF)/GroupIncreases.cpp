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
#define sor(x) sort(all(x))
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
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        lli a1=1e9,a2=1e9;
        lli ct=0;
        f(i,n){
            if(a1>=a[i] && a2>=a[i]){
                if(a1>a2) a2=a[i];
                else a1=a[i];
            }
            else if(a1>=a[i]) a1=a[i];
            else if(a2>=a[i]) a2=a[i];
            else{
                if(a1>a2) a2=a[i];
                else a1=a[i];
                ct++;
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}