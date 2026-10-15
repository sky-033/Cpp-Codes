
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
        lli n,m;
        cin>>n>>m;
        vector<string> a(n);
        f(i,n) cin>>a[i];
        lli ct=0,count=0;
        vll zeroes;
        f(i,n){
            ct=0;
            lli size=a[i].size();
            for(lli j=size-1;j>=0;j--){
                if(a[i][j]=='0') ct++;
                else break;
            }
            count+=ct;
            if(ct!=0) zeroes.push_back(ct);
        }
        lli total=0;
        f(i,n){
            lli s=a[i].size();
            total+=s;
        }
        total-=count;
        sor(zeroes);
        reverse(all(zeroes));
        ff(1,zeroes.size(),2){
            total+=zeroes[i];
        }
        if(total>=(m+1)) cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;
    }
    return 0;
}