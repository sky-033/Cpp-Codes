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
        lli a,b,x,y;
        cin>>a>>b>>x>>y;
        if(b<a){
            if(a^1==b) cout<<y<<endl;
            else cout<<-1<<endl;
        }
        else{
            if(x>=y) cout<<x*(b-a)<<endl;
            else{
                lli cost=0;
                lli num=b-a;
                if(num&1){
                    if(a&1){
                        cost=(num/2+1)*x;
                        cost+=num/2*y;
                    }
                    else{
                        cost=(num/2+1)*y;
                        cost+=num/2*x;
                    }
                }
                else{
                    cost=x*num/2;
                    cost+=y*num/2;
                }
                cout<<cost<<endl;
            }
        }
    }
    return 0;
}