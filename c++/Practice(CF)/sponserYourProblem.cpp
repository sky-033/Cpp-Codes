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
        lli l,r;
        cin>>l>>r;
        string L=to_string(l),R=to_string(r);
        lli ans=0;
        lli size=L.size(),indx=size;
        f(i,size){
            if(L[i]==R[i]){
                ans+=2;
            }
            else{
                indx=i;
                break;
            }
        }
        lli num1=0,num2=0;
        for(lli i=indx;i<size;i++){
            lli a1=L[i]-'0';
            lli a2=R[i]-'0';
            if(i==indx){
                num1=a1;
                num2=a2;
            }
            else{
                num1=num1*10+a1;
                num2=num2*10+a2;
            }
            if(num2-num1==1) ans++;
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}