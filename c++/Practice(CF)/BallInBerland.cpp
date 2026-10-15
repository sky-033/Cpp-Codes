#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vpw vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
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
    int t;
    cin>>t;
    while(t--){
        lli a,b,k;
        cin>>a>>b>>k;
        vll boys(k),girls(k);
        f(i,k) cin>>boys[i];
        f(i,k) cin>>girls[i];
        vector<set<lli>> boyGirl(a+1);
        vector<set<lli>> girlBoy(b+1);
        lli sum=0;
        f(i,k){
            boyGirl[boys[i]].insert(girls[i]);
            girlBoy[girls[i]].insert(boys[i]);
        }
        lli ans=0;
        ff(1,a,1){
            fa(boyGirl[i]){
                lli ct=k-boyGirl[i].size()-sum;
                ct-=distance(girlBoy[it].lower_bound(i+1),girlBoy[it].end());
                ans+=ct;
            }
            sum+=boyGirl[i].size();
        }
        cout<<ans<<endl;
    }
    return 0;
}