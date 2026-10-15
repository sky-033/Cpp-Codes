#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
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
        string a,b,A;
        cin>>a>>b;
        set<char> dif;
        vector<char> diff;
        f(i,n){
            if(a[i]!=b[i]) dif.insert(a[i]);
        }
        fa(dif) diff.push_back(it);
        lli ss=diff.size();
        if(k>=ss){
            cout<<n*(n+1)/2<<"\n";
            continue;
        }
        k=min(k,ss);
        lli ans=0;
        for(lli i=0;i<(1LL<<ss);i++){
            if(__builtin_popcount(i)>k) continue;
            lli maxi=0;
            A=a;
            for(lli j=0;j<ss;j++){
                if(i&(1<<j)){
                    for(int x=0;x<n;x++){
                        if(A[x]==diff[j]) A[x]=b[x];
                    }
                }
            }
            lli l=0,h=0;
            while(h<n){
                if(A[h]==b[h]) h++;
                else{
                    lli len=h-l;
                    maxi+=(len)*(len+1)/2;
                    h++;
                    l=h;
                }
            }
            lli len=h-l;
            maxi+=(len)*(len+1)/2;
            ans=max(ans,maxi);
        }
        cout<<ans<<"\n";
    }
    return 0;
}