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

vll factors(lli n){
    vll temp;
    for(lli i=1;i*i<=n;i++){
        if(n%i==0) temp.push_back(i);
        if(i!=n/i) temp.push_back(n/i);
    }
    return temp;
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
        vll Factors=factors(n);
        sor(Factors);
        lli it=lower_bound(all(Factors),k)-Factors.begin();
        if(n<=k) cout<<1<<endl;
        else{
            if(Factors[it]>k){
                cout<<n/Factors[it-1]<<endl;
            }
            else{
                cout<<n/Factors[it]<<endl;
            }
        }
    }
    return 0;
}