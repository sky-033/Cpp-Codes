// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define g(j,n) for(lli j=0;j<n;j++)
// #define h(k,n) for(lli k=0;k<n;k++)
// #define rf(i,n) for(lli i=n-1;i>=0;i--)
// #define ff(a,b,c) for(lli i=a;i<b;i+=c)
// #define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
// #define fa(v) for (auto &it : v) 
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sor(x) sort(all(x))
// #define rsor(x) sort(rall(x))
// #define setbits(x) __builtin_popcountll(x)
// const lli N=2e5+10;
// const lli M=1e9+7; 

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         lli n;
//         cin>>n;
//         if(n==1) cout<<1<<endl;
//         else if(n==2 || n==3 || n==4) cout<<2<<endl;
//         else{
//             lli k=4,ct=2;
//             while(k<n){
//                 k=k*2+2;
//                 ct++;
//             }
//             cout<<ct<<endl;
//         }
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define g(j,n) for(lli j=0;j<n;j++)
// #define h(k,n) for(lli k=0;k<n;k++)
// #define rf(i,n) for(lli i=n-1;i>=0;i--)
// #define ff(a,b,c) for(lli i=a;i<b;i+=c)
// #define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
// #define fa(v) for (auto &it : v) 
// #define all(x) (x).begin(), (x).end()
// #define sor(x) sort(all(x))
// #define setbits(x) __builtin_popcountll(x)
// const lli N=2e5+10;
// const lli M=1e9+7; 

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         lli n,m,k;
//         cin>>n>>m>>k;
//         for(lli i=n;i>m;i--){
//             cout<<i<<" ";
//         }
//         for(lli i=1;i<=m;i++){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }



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

lli binExpItr(lli a,lli b){
    a%=M;
    lli ans=1;
    while(b>0){
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        lli val=binExpItr(2,k)-1;
        lli len=log2(val)+1;
        lli ans=binExpItr(n,len);
        cout<<ans<<endl;
    }
    return 0;
}