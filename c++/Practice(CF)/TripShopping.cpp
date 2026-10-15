#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
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
        lli n,k;
        cin>>n>>k;
        vector<pair<pair<lli,lli>,lli>> ab;
        vll a(n),b(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        lli diff=0;
        f(i,n){
            ab.push_back({{a[i],b[i]},abs(a[i]-b[i])});
            diff+=abs(a[i]-b[i]);
        }
        sor(ab);
        auto it=ab.begin();
        auto prv=it;
        it++;
        lli ans=1e18;
        for(;it!=ab.end();it++){
            vector<lli> temp;
            temp.push_back(prv->first.first);
            temp.push_back(prv->first.second);
            temp.push_back(it->first.first);
            temp.push_back(it->first.second);
            sor(temp);
            lli t=0;
            for(lli i=0;i<4;i++){
                if(i<2) t-=temp[i];
                else t+=temp[i];
            }
            lli dif=prv->second+it->second;
            prv++;
            lli val=diff-dif+t;
            ans=min(ans,val);
        }
        cout<<ans<<endl;
    }
    return 0;
}