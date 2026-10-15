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
        vll a(n),A;
        f(i,n) cin>>a[i];
        bool flag=false;
        f(i,n){
            if(a[i]>0) flag=true;
            if(a[i]!=0) A.push_back(a[i]);
        }
        sor(A);
        if(A.size()==0) cout<<-1<<endl;
        else{
            lli x=A.size();
            if(flag){
                cout<<A[x-1]<<" "<<A[x-1]<<endl;
            }
            else{
                rsor(A);
                cout<<A[x-1]<<" "<<A[x-1]<<endl;
            }
        }
    }
    return 0;
}