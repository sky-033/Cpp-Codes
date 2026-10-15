
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
// #define bitlen(x) 64-__builtin_clzll(x)
// const lli N=2e5+10;
// const lli M=1e9+7; 

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     lli n;
//     cin>>n;
//     string s;
//     cin>>s;
//     lli m=0,p=0;
//     f(i,n){
//         if(s[i]=='+') p++;
//         else m++;
//     }
//     lli q;
//     cin>>q;
//     f(i,q){
//         lli a,b;
//         cin>>a>>b;
//         if(a==b){
//             if(m==p) cout<<"YES"<<endl;
//             else cout<<"NO"<<endl;
//         }
//         else{
//             if((a*p-b*m)%(a-b)==0){
//                 lli val=(a*p-b*m)/(a-b);
//                 if(val<=n && val>=0) cout<<"YES"<<endl;
//                 else cout<<"NO"<<endl;
//             }
//             else cout<<"NO"<<endl;
//         }
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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    string s;
    cin>>s;
    lli p=0,m=0;
    f(i,n){
        if(s[i]=='+') p++;
        else m++;
    }
    lli q;
    cin>>q;
    bool flag=false;
    if(p==m) flag=true;
    f(i,q){
        lli a,b;
        cin>>a>>b;
        if(b>a) swap(a,b);
        if(flag) cout<<"YES"<<endl;
        else{
            lli mini=min(p,m);
            lli maxi=max(p,m);
            lli minVal=maxi*b;
            lli l=0,h=mini,mid;
            while(h-l>1){
                mid=(l+h)/2;
                lli a1=mid,a2=mini-a1;
                if(a*a1+b*a2<minVal) l=mid+1;
                else h=mid;
            }
            if(a*l+b*(mini-l)==minVal) cout<<"YES"<<endl;
            else if(a*h+b*(mini-h)==minVal) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}