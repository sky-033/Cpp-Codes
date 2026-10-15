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
        lli n,m;
        cin>>n>>m;
        vll a(m);
        f(i,m) cin>>a[i];
        lli affected=m;
        vll gaps;
        sor(a);
        ff(1,m,1){
            if(a[i]-a[i-1]-1>0) gaps.push_back(a[i]-a[i-1]-1);
        }
        if(a[0]-1+n-a[m-1]>0) gaps.push_back(a[0]-1+n-a[m-1]);
        rsor(gaps);
        lli days=2,left=0;
        fa(gaps){
            if(it>=days*2-1){
                affected+=(2*(days-2)+1);
            }
            else if(it>=(days-1)*2-1){
                affected+=(it-1);
            }
            else{
                affected+=it;
            }
            days+=2;
        }
        cout<<affected<<endl;
    }
    return 0;
}