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
        lli n,d;
        cin>>n>>d;
        vll ans;
        ans.push_back(1);
        if(n>=3 || (d==3 || d==6 || d==9)) ans.push_back(3);
        if(d==5) ans.push_back(5);
        if(n>=3 || (d==7)) ans.push_back(7);
        bool check=false;
        if(n==2){
            if(d==9) check=true;
        }
        if(!check){
            if(n==3){
                if((d*6)%9==0) check=true;
            }
            else if(n==4){
                if((d*24)%9==0) check=true;
            }
            else if(n==5){
                if((d*120)%9==0) check=true;
            }
            else{
                check=true;
            }
        }
        if(check) ans.push_back(9);
        fa(ans) cout<<it<<" ";
        cout<<endl;
        
    }
    return 0;
}